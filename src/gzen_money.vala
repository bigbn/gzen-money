/*
 * main.c
 * Copyright (C) 2015 Pavel Shabardin <bigbn@mail.ru>
 * 
 * gzen-money is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * gzen-money is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

using GLib;
using Gtk;
using Gee;
using GnomeKeyring;

const string APP_NAME = "Gzen-money";

delegate void MyDelegateType (string name);


public class Main : Object
{

	/* 
	 * Uncomment this line when you are done testing and building a tarball
	 * or installing
	 */
	//const string UI_FILE = Config.PACKAGE_DATA_DIR + "/ui/" + "gzen_money.ui";
	const string UI_FILE = "src/gzen_money.ui";
	private Gtk.Button login_button;
	private Zenmoney zenmoney;
	private DbusServer dbus_server;
	/* ANJUTA: Widgets declaration for gzen_money.ui - DO NOT REMOVE */
	

	public Main ()
	{

		zenmoney = new Zenmoney();
		getCredentials ();
			
		message ("Registering d-bus server");

		MyDelegateType deleg = super_test;
		
		Bus.own_name (BusType.SESSION, "org.gzen_money.Demo", BusNameOwnerFlags.NONE,
                  on_bus_aquired,
                  on_name_acquired,
             	  on_name_lost);
		
		try 
		{
			var builder = new Builder();
			builder.add_from_file (UI_FILE);

			builder.connect_signals (this);

			var window = builder.get_object ("application_window") as Window;
			window.destroy.connect(Gtk.main_quit);

			login_button = builder.get_object("login_button") as Gtk.Button;
			login_button.clicked.connect(login);

			/* ANJUTA: Widgets initialization for gzen_money.ui - DO NOT REMOVE */
			window.show_all();

		}
		catch (Error e) {
			stderr.printf ("Could not load UI: %s\n", e.message);
		}



	}

	
    private void on_name_acquired () {
        print ("name acquired\n");
    }  

    private void on_name_lost () {
        print ("name_lost\n");
    }

	
	private void login(Widget source) {
		
		zenmoney.getAccessToken_A();
		print("ayay\n");
	}


	private void super_test(string a) {
		message ("super_test");
	}

	public void on_bus_aquired (DBusConnection conn) {
		try {			
			this.dbus_server = new DbusServer();
		    conn.register_object ("/org/gzen_money/demo", this.dbus_server);
			this.dbus_server.on_consumer_key_received.connect(this.onMessageHandler);
		} catch (IOError e) {
		    stderr.printf ("Could not register service\n");
		}
	}

	private void onMessageHandler(string verify) {
		message(verify);		

		string[] parts = verify.split("&");
		string verifier = "";
		foreach(string part in parts) {
			string[] p = part.split("=");
			if(p[0] == "oauth_verifier") {
				verifier = p[1];
			}
		}
		message (verifier);
		Map<string, string> secret = zenmoney.getAccessToken_B(verifier);
		saveCredentials(secret);
	}


	private void getCredentials () {
		message ("Get credentials");
		var attributes = new GnomeKeyring.AttributeList();
		attributes.append_string("application", APP_NAME);
		//attributes.append_string("consumer_key", APP_NAME);
		var search_result = new GLib.List<GnomeKeyring.Found>();
        GnomeKeyring.find_items_sync(GnomeKeyring.ItemType.NETWORK_PASSWORD, attributes, out search_result);

		
		string secret = "";
		foreach (GnomeKeyring.Found Item in search_result) {
			secret = Item.secret; 
			message(Item.secret);					 
			message(((uint)Item.item_id).to_string());
		}
		
		zenmoney.init("215923621d51fb49f10b0a98bc579f", secret);
		message ("Loading home");
		zenmoney.home_timeline();
		message ("Home loaded");
	}
	
	private void saveCredentials(Map<string, string> secret) {
		GnomeKeyring.create_sync(APP_NAME, "wattapas");
		var attributes = new GnomeKeyring.AttributeList();
		attributes.append_string("application", APP_NAME);
		attributes.append_string("consumer_key", secret.get("consumer_key"));
		uint32 item_id = 0;
		GnomeKeyring.item_create_sync(APP_NAME, GnomeKeyring.ItemType.NETWORK_PASSWORD, "Gzen-money keyring", attributes, secret.get("consumer_secret") , true, out item_id); 		
	}
	
	static int main (string[] args) 
	{
				
		message ("Starting main loop");			
		Gtk.init (ref args);

		var app = new Main ();
		Gtk.main ();
		return 0;
	}
}

