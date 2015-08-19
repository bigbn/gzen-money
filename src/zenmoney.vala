using Gee;
using Soup;
using Json;

const string OWNER_INFO_URL = "http://api.zenmoney.ru/v1/owner/";

public class Zenmoney {
	
	private OauthZenmoney ot;

	public Zenmoney() {
		print("New Zenmoney /n");
		ot = new OauthZenmoney();
	}

	public void init(string token, string token_secret) {
		ot.init(token, token_secret);
	}

	public void getAccessToken_A() {
		ot.getAccessToken_A();
	}

	public Map<string, string> getAccessToken_B(string pin) {
		return ot.getAccessToken_B(pin);
	}

	public Json.Parser home_timeline() {
		print("Home_timeline /n");
		Soup.Session session = new Soup.SessionAsync();
		Soup.Message message = ot.Auth("POST", OWNER_INFO_URL , null);
		session.send_message(message);
		var parser = new Json.Parser();
		try {
			print("response: "+(string)message.response_body.flatten().data+"\n");
			parser.load_from_data((string)message.response_body.flatten().data, -1);
		} catch(GLib.Error e) {
			print("Error: "+e.message);
		}
		print("response"+(string)message.response_body.flatten().data);
		return parser;
	}
}