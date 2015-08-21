/*
 * dbus_server.c
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

/**
* D-Bus interface for external communications.
* @class DbusServer
* @property onMessage {signal} emits, when any new D-Bus messages are received.
*/
[DBus (name = "org.gzen_money.Demo")]
public class DbusServer : Object {

	public signal void on_consumer_key_received(string verify);

  /**
  * Receives oauth secret and pass it to application via signal.
  * @method set_consumer_key
  * @param {string} key
  * @emits DbusServer#on_consumer_key_received
  */
  public void set_consumer_key(string key) {
    this.on_consumer_key_received(key);
  }
}

