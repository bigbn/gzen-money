using OAuth;
using Soup;
using Gee;

const string REALM = "";
const string KEY = "215923636aa71c72ca3431990e5ff0";
const string SECRET = "fab63a4738";

const string REQUEST_TOKEN_URL = "http://api.zenmoney.ru/oauth/request_token";
const string REQUEST_AUTHORIZE_URL = "http://api.zenmoney.ru/access/?oauth_callback='gzen-pass://verify'&oauth_token=%s";
const string ACCESS_TOKEN_URL = "http://api.zenmoney.ru/oauth/access_token";

public class OauthZenmoney {
	
	private OAuth.Client client;
	private string token = "";

	public OauthZenmoney() {
		message("Creating instance of new Oauth client");
		client = new OAuth.Client(REALM, KEY, new OAuth.HMAC_SHA1(SECRET));
	}

	public void init(string token, string token_secret) {
		message("Setting token: %s , %s", token, token_secret);
		client.set_token(token, token_secret);
	}

	public void getAccessToken_A() {
		message("Getting access token for key: " + KEY);

		const string method = "POST";	
		const string callback = "oob";		
		
		
		Map<string, string> request;
		request = client.request_token(method, REQUEST_TOKEN_URL, callback);
		message("Preparing request");
		string request_auth = request["Authorization"];
		
		var session = new Soup.SessionSync();
		var smessage = new Soup.Message(method, REQUEST_TOKEN_URL);
		smessage.request_headers.append("Authorization", request_auth);

		session.send_message(smessage);
		string response = (string)smessage.response_body.flatten().data;
		message ("Token response: " + response);
		
		string[] parts = response.split("&");
		string token_secret = "";
		foreach(string part in parts) {
			string[] p = part.split("=");
			if(p[0] == "oauth_token") {
				token = p[1];
			} else if(p[0] == "oauth_token_secret") {
				token_secret = p[1];
			}
		}

		message("Token catched:" + token);
		
		string url = "";
		try {
			url = client.auth_token(REQUEST_AUTHORIZE_URL, token, token_secret, "true");
			message("Token URL:" + url);
		} catch(OAuth.Error e) {
			print("Error: "+e.message);
		}

		try {
			print(url+"\n");
			Process.spawn_command_line_async("xdg-open '"+url+"'");
		} catch(SpawnError e) {
			print("Error: "+e.message);
		}
	}
		
	public Map<string, string> getAccessToken_B(string pin) {
		const string method = "POST";
		 
		Map<string, string> access = new HashMap<string, string>();
		try {
			access = client.access_token(method, ACCESS_TOKEN_URL, token, pin);
		} catch(OAuth.Error e) {
			print("Error: "+e.message);
		}
		string access_auth = access["Authorization"];

		// TODO: Why the fuck is Async not working?
		var session = new Soup.SessionSync();
		var message = new Soup.Message(method, ACCESS_TOKEN_URL);
		message.request_headers.append("Authorization", access_auth);

		
		session.send_message(message);
		string[] parts = ((string)message.response_body.data).split("&");
		warning (((string)message.response_body.data));
		
		string token = "";
		string token_secret = "";
		foreach(string part in parts) {
			string[] p = part.split("=");
			if(p[0] == "oauth_token") {
				token = p[1];
			} else if(p[0] == "oauth_token_secret") {
				token_secret = p[1];
			} 
		}

		
		client.set_token(token, token_secret);
		var ret = new HashMap<string, string>();
		ret.set("consumer_key", token);
		ret.set("consumer_secret", token_secret);
		return ret;
	}

	public Soup.Message Auth(string method,	 string url, MultiMap<string, string>? parameters = null) {
		string myurl = url;
		if(parameters != null ) {
			myurl += "?";
			foreach(var key in parameters.get_keys()) {
				foreach(var value in parameters.get(key)) {
					myurl += key + "=" + value + "&";
				}
			}
			myurl = myurl[0:myurl.length-1];
		}
		print(myurl+"\n");
		var message = new Soup.Message(method, myurl);
		var oauth_header = client.authenticate(method, url, parameters)["Authorization"];
		message.request_headers.append("Authorization", oauth_header);
		return message;
	}
}
