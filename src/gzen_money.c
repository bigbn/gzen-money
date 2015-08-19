/* gzen_money.c generated by valac 0.28.1, the Vala compiler
 * generated from gzen_money.vala, do not modify */

/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
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

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <stdio.h>
#include <gee.h>
#include <gnome-keyring.h>
#include <json-glib/json-glib.h>


#define TYPE_MAIN (main_get_type ())
#define MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MAIN, Main))
#define MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MAIN, MainClass))
#define IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MAIN))
#define IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MAIN))
#define MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MAIN, MainClass))

typedef struct _Main Main;
typedef struct _MainClass MainClass;
typedef struct _MainPrivate MainPrivate;

#define TYPE_ZENMONEY (zenmoney_get_type ())
#define ZENMONEY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ZENMONEY, Zenmoney))
#define ZENMONEY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ZENMONEY, ZenmoneyClass))
#define IS_ZENMONEY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ZENMONEY))
#define IS_ZENMONEY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ZENMONEY))
#define ZENMONEY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ZENMONEY, ZenmoneyClass))

typedef struct _Zenmoney Zenmoney;
typedef struct _ZenmoneyClass ZenmoneyClass;

#define TYPE_DBUS_SERVER (dbus_server_get_type ())
#define DBUS_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DBUS_SERVER, DbusServer))
#define DBUS_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DBUS_SERVER, DbusServerClass))
#define IS_DBUS_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DBUS_SERVER))
#define IS_DBUS_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DBUS_SERVER))
#define DBUS_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DBUS_SERVER, DbusServerClass))

typedef struct _DbusServer DbusServer;
typedef struct _DbusServerClass DbusServerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _zenmoney_unref0(var) ((var == NULL) ? NULL : (var = (zenmoney_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define __g_list_free___vala_GnomeKeyringFound_free0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free___vala_GnomeKeyringFound_free0_ (var), NULL)))
#define __vala_GnomeKeyringFound_free0(var) ((var == NULL) ? NULL : (var = (_vala_GnomeKeyringFound_free (var), NULL)))
#define _g_array_unref0(var) ((var == NULL) ? NULL : (var = (g_array_unref (var), NULL)))

typedef void (*MyDelegateType) (const gchar* name, void* user_data);
struct _Main {
	GObject parent_instance;
	MainPrivate * priv;
};

struct _MainClass {
	GObjectClass parent_class;
};

struct _MainPrivate {
	GtkButton* login_button;
	Zenmoney* zenmoney;
	DbusServer* dbus_server;
};


static gpointer main_parent_class = NULL;

#define APP_NAME "Gzen-money"
GType main_get_type (void) G_GNUC_CONST;
gpointer zenmoney_ref (gpointer instance);
void zenmoney_unref (gpointer instance);
GParamSpec* param_spec_zenmoney (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_zenmoney (GValue* value, gpointer v_object);
void value_take_zenmoney (GValue* value, gpointer v_object);
gpointer value_get_zenmoney (const GValue* value);
GType zenmoney_get_type (void) G_GNUC_CONST;
GType dbus_server_get_type (void) G_GNUC_CONST;
guint dbus_server_register_object (void* object, GDBusConnection* connection, const gchar* path, GError** error);
#define MAIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_MAIN, MainPrivate))
enum  {
	MAIN_DUMMY_PROPERTY
};
#define MAIN_UI_FILE "src/gzen_money.ui"
Main* main_new (void);
Main* main_construct (GType object_type);
Zenmoney* zenmoney_new (void);
Zenmoney* zenmoney_construct (GType object_type);
static void main_getCredentials (Main* self);
static void main_super_test (Main* self, const gchar* a);
static void _main_super_test_my_delegate_type (const gchar* name, gpointer self);
void main_on_bus_aquired (Main* self, GDBusConnection* conn);
static void _main_on_bus_aquired_gbus_acquired_callback (GDBusConnection* connection, const gchar* name, gpointer self);
static void main_on_name_acquired (Main* self);
static void _main_on_name_acquired_gbus_name_acquired_callback (GDBusConnection* connection, const gchar* name, gpointer self);
static void main_on_name_lost (Main* self);
static void _main_on_name_lost_gbus_name_lost_callback (GDBusConnection* connection, const gchar* name, gpointer self);
static void _gtk_main_quit_gtk_widget_destroy (GtkWidget* _sender, gpointer self);
static void main_login (Main* self, GtkWidget* source);
static void _main_login_gtk_button_clicked (GtkButton* _sender, gpointer self);
void zenmoney_getAccessToken_A (Zenmoney* self);
DbusServer* dbus_server_new (void);
DbusServer* dbus_server_construct (GType object_type);
static void main_onMessageHandler (Main* self, const gchar* verify);
static void _main_onMessageHandler_dbus_server_on_message (DbusServer* _sender, const gchar* verify, gpointer self);
GeeMap* zenmoney_getAccessToken_B (Zenmoney* self, const gchar* pin);
static void main_saveCredentials (Main* self, GeeMap* secret);
static void _vala_GnomeKeyringFound_free (GnomeKeyringFound* self);
static void __vala_GnomeKeyringFound_free0_ (gpointer var);
static void _g_list_free___vala_GnomeKeyringFound_free0_ (GList* self);
static GnomeKeyringFound* _vala_GnomeKeyringFound_copy (GnomeKeyringFound* self);
void zenmoney_init (Zenmoney* self, const gchar* token, const gchar* token_secret);
JsonParser* zenmoney_home_timeline (Zenmoney* self);
static gint main_main (gchar** args, int args_length1);
static void main_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


static void _main_super_test_my_delegate_type (const gchar* name, gpointer self) {
	main_super_test ((Main*) self, name);
}


static void _main_on_bus_aquired_gbus_acquired_callback (GDBusConnection* connection, const gchar* name, gpointer self) {
	main_on_bus_aquired ((Main*) self, connection);
}


static void _main_on_name_acquired_gbus_name_acquired_callback (GDBusConnection* connection, const gchar* name, gpointer self) {
	main_on_name_acquired ((Main*) self);
}


static void _main_on_name_lost_gbus_name_lost_callback (GDBusConnection* connection, const gchar* name, gpointer self) {
	main_on_name_lost ((Main*) self);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _gtk_main_quit_gtk_widget_destroy (GtkWidget* _sender, gpointer self) {
	gtk_main_quit ();
}


static void _main_login_gtk_button_clicked (GtkButton* _sender, gpointer self) {
	main_login ((Main*) self, _sender);
}


Main* main_construct (GType object_type) {
	Main * self = NULL;
	Zenmoney* _tmp0_ = NULL;
	MyDelegateType deleg = NULL;
	void* deleg_target = NULL;
	GDestroyNotify deleg_target_destroy_notify = NULL;
	GError * _inner_error_ = NULL;
	self = (Main*) g_object_new (object_type, NULL);
	_tmp0_ = zenmoney_new ();
	_zenmoney_unref0 (self->priv->zenmoney);
	self->priv->zenmoney = _tmp0_;
	main_getCredentials (self);
	g_message ("gzen_money.vala:51: Registering d-bus server");
	deleg = _main_super_test_my_delegate_type;
	deleg_target = g_object_ref (self);
	deleg_target_destroy_notify = g_object_unref;
	g_bus_own_name_with_closures (G_BUS_TYPE_SESSION, "org.gzen_money.Demo", G_BUS_NAME_OWNER_FLAGS_NONE, (GClosure*) ((_main_on_bus_aquired_gbus_acquired_callback == NULL) ? NULL : g_cclosure_new ((GCallback) _main_on_bus_aquired_gbus_acquired_callback, g_object_ref (self), g_object_unref)), (GClosure*) ((_main_on_name_acquired_gbus_name_acquired_callback == NULL) ? NULL : g_cclosure_new ((GCallback) _main_on_name_acquired_gbus_name_acquired_callback, g_object_ref (self), g_object_unref)), (GClosure*) ((_main_on_name_lost_gbus_name_lost_callback == NULL) ? NULL : g_cclosure_new ((GCallback) _main_on_name_lost_gbus_name_lost_callback, g_object_ref (self), g_object_unref)));
	{
		GtkBuilder* builder = NULL;
		GtkBuilder* _tmp1_ = NULL;
		GtkWindow* window = NULL;
		GObject* _tmp2_ = NULL;
		GtkWindow* _tmp3_ = NULL;
		GtkWindow* _tmp4_ = NULL;
		GObject* _tmp5_ = NULL;
		GtkButton* _tmp6_ = NULL;
		GtkButton* _tmp7_ = NULL;
		GtkWindow* _tmp8_ = NULL;
		_tmp1_ = gtk_builder_new ();
		builder = _tmp1_;
		gtk_builder_add_from_file (builder, MAIN_UI_FILE, &_inner_error_);
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			_g_object_unref0 (builder);
			goto __catch0_g_error;
		}
		gtk_builder_connect_signals (builder, self);
		_tmp2_ = gtk_builder_get_object (builder, "application_window");
		_tmp3_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp2_, gtk_window_get_type ()) ? ((GtkWindow*) _tmp2_) : NULL);
		window = _tmp3_;
		_tmp4_ = window;
		g_signal_connect ((GtkWidget*) _tmp4_, "destroy", (GCallback) _gtk_main_quit_gtk_widget_destroy, NULL);
		_tmp5_ = gtk_builder_get_object (builder, "login_button");
		_tmp6_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp5_, gtk_button_get_type ()) ? ((GtkButton*) _tmp5_) : NULL);
		_g_object_unref0 (self->priv->login_button);
		self->priv->login_button = _tmp6_;
		_tmp7_ = self->priv->login_button;
		g_signal_connect_object (_tmp7_, "clicked", (GCallback) _main_login_gtk_button_clicked, self, 0);
		_tmp8_ = window;
		gtk_widget_show_all ((GtkWidget*) _tmp8_);
		_g_object_unref0 (window);
		_g_object_unref0 (builder);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		FILE* _tmp9_ = NULL;
		GError* _tmp10_ = NULL;
		const gchar* _tmp11_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp9_ = stderr;
		_tmp10_ = e;
		_tmp11_ = _tmp10_->message;
		fprintf (_tmp9_, "Could not load UI: %s\n", _tmp11_);
		_g_error_free0 (e);
	}
	__finally0:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		(deleg_target_destroy_notify == NULL) ? NULL : (deleg_target_destroy_notify (deleg_target), NULL);
		deleg = NULL;
		deleg_target = NULL;
		deleg_target_destroy_notify = NULL;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	(deleg_target_destroy_notify == NULL) ? NULL : (deleg_target_destroy_notify (deleg_target), NULL);
	deleg = NULL;
	deleg_target = NULL;
	deleg_target_destroy_notify = NULL;
	return self;
}


Main* main_new (void) {
	return main_construct (TYPE_MAIN);
}


static void main_on_name_acquired (Main* self) {
	g_return_if_fail (self != NULL);
	g_print ("name acquired\n");
}


static void main_on_name_lost (Main* self) {
	g_return_if_fail (self != NULL);
	g_print ("name_lost\n");
}


static void main_login (Main* self, GtkWidget* source) {
	Zenmoney* _tmp0_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (source != NULL);
	_tmp0_ = self->priv->zenmoney;
	zenmoney_getAccessToken_A (_tmp0_);
	g_print ("ayay\n");
}


static void main_super_test (Main* self, const gchar* a) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (a != NULL);
	g_message ("gzen_money.vala:103: super_test");
}


static void _main_onMessageHandler_dbus_server_on_message (DbusServer* _sender, const gchar* verify, gpointer self) {
	main_onMessageHandler ((Main*) self, verify);
}


void main_on_bus_aquired (Main* self, GDBusConnection* conn) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (conn != NULL);
	{
		DbusServer* _tmp0_ = NULL;
		GDBusConnection* _tmp1_ = NULL;
		DbusServer* _tmp2_ = NULL;
		DbusServer* _tmp3_ = NULL;
		_tmp0_ = dbus_server_new ();
		_g_object_unref0 (self->priv->dbus_server);
		self->priv->dbus_server = _tmp0_;
		_tmp1_ = conn;
		_tmp2_ = self->priv->dbus_server;
		dbus_server_register_object (_tmp2_, _tmp1_, "/org/gzen_money/demo", &_inner_error_);
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			if (_inner_error_->domain == G_IO_ERROR) {
				goto __catch1_g_io_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_tmp3_ = self->priv->dbus_server;
		g_signal_connect_object (_tmp3_, "on-message", (GCallback) _main_onMessageHandler_dbus_server_on_message, self, 0);
	}
	goto __finally1;
	__catch1_g_io_error:
	{
		GError* e = NULL;
		FILE* _tmp4_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp4_ = stderr;
		fprintf (_tmp4_, "Could not register service\n");
		_g_error_free0 (e);
	}
	__finally1:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void main_onMessageHandler (Main* self, const gchar* verify) {
	const gchar* _tmp0_ = NULL;
	gchar** parts = NULL;
	const gchar* _tmp1_ = NULL;
	gchar** _tmp2_ = NULL;
	gchar** _tmp3_ = NULL;
	gint parts_length1 = 0;
	gint _parts_size_ = 0;
	gchar* verifier = NULL;
	gchar* _tmp4_ = NULL;
	gchar** _tmp5_ = NULL;
	gint _tmp5__length1 = 0;
	const gchar* _tmp15_ = NULL;
	GeeMap* secret = NULL;
	Zenmoney* _tmp16_ = NULL;
	const gchar* _tmp17_ = NULL;
	GeeMap* _tmp18_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (verify != NULL);
	_tmp0_ = verify;
	g_message ("gzen_money.vala:117: %s", _tmp0_);
	_tmp1_ = verify;
	_tmp3_ = _tmp2_ = g_strsplit (_tmp1_, "&", 0);
	parts = _tmp3_;
	parts_length1 = _vala_array_length (_tmp2_);
	_parts_size_ = parts_length1;
	_tmp4_ = g_strdup ("");
	verifier = _tmp4_;
	_tmp5_ = parts;
	_tmp5__length1 = parts_length1;
	{
		gchar** part_collection = NULL;
		gint part_collection_length1 = 0;
		gint _part_collection_size_ = 0;
		gint part_it = 0;
		part_collection = _tmp5_;
		part_collection_length1 = _tmp5__length1;
		for (part_it = 0; part_it < _tmp5__length1; part_it = part_it + 1) {
			gchar* _tmp6_ = NULL;
			gchar* part = NULL;
			_tmp6_ = g_strdup (part_collection[part_it]);
			part = _tmp6_;
			{
				gchar** p = NULL;
				const gchar* _tmp7_ = NULL;
				gchar** _tmp8_ = NULL;
				gchar** _tmp9_ = NULL;
				gint p_length1 = 0;
				gint _p_size_ = 0;
				gchar** _tmp10_ = NULL;
				gint _tmp10__length1 = 0;
				const gchar* _tmp11_ = NULL;
				_tmp7_ = part;
				_tmp9_ = _tmp8_ = g_strsplit (_tmp7_, "=", 0);
				p = _tmp9_;
				p_length1 = _vala_array_length (_tmp8_);
				_p_size_ = p_length1;
				_tmp10_ = p;
				_tmp10__length1 = p_length1;
				_tmp11_ = _tmp10_[0];
				if (g_strcmp0 (_tmp11_, "oauth_verifier") == 0) {
					gchar** _tmp12_ = NULL;
					gint _tmp12__length1 = 0;
					const gchar* _tmp13_ = NULL;
					gchar* _tmp14_ = NULL;
					_tmp12_ = p;
					_tmp12__length1 = p_length1;
					_tmp13_ = _tmp12_[1];
					_tmp14_ = g_strdup (_tmp13_);
					_g_free0 (verifier);
					verifier = _tmp14_;
				}
				p = (_vala_array_free (p, p_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (part);
			}
		}
	}
	_tmp15_ = verifier;
	g_message ("gzen_money.vala:127: %s", _tmp15_);
	_tmp16_ = self->priv->zenmoney;
	_tmp17_ = verifier;
	_tmp18_ = zenmoney_getAccessToken_B (_tmp16_, _tmp17_);
	secret = _tmp18_;
	main_saveCredentials (self, secret);
	_g_object_unref0 (secret);
	_g_free0 (verifier);
	parts = (_vala_array_free (parts, parts_length1, (GDestroyNotify) g_free), NULL);
}


static void _vala_GnomeKeyringFound_free (GnomeKeyringFound* self) {
	g_boxed_free (gnome_keyring_found_get_type (), self);
}


static void __vala_GnomeKeyringFound_free0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (_vala_GnomeKeyringFound_free (var), NULL));
}


static void _g_list_free___vala_GnomeKeyringFound_free0_ (GList* self) {
	g_list_foreach (self, (GFunc) __vala_GnomeKeyringFound_free0_, NULL);
	g_list_free (self);
}


static GnomeKeyringFound* _vala_GnomeKeyringFound_copy (GnomeKeyringFound* self) {
	return g_boxed_copy (gnome_keyring_found_get_type (), self);
}


static gpointer __vala_GnomeKeyringFound_copy0 (gpointer self) {
	return self ? _vala_GnomeKeyringFound_copy (self) : NULL;
}


static void main_getCredentials (Main* self) {
	GnomeKeyringAttributeList* attributes = NULL;
	GnomeKeyringAttributeList* _tmp0_ = NULL;
	GnomeKeyringAttributeList* _tmp1_ = NULL;
	GList* search_result = NULL;
	GnomeKeyringAttributeList* _tmp2_ = NULL;
	GList* _tmp3_ = NULL;
	gchar* secret = NULL;
	gchar* _tmp4_ = NULL;
	GList* _tmp5_ = NULL;
	Zenmoney* _tmp16_ = NULL;
	const gchar* _tmp17_ = NULL;
	Zenmoney* _tmp18_ = NULL;
	JsonParser* _tmp19_ = NULL;
	JsonParser* _tmp20_ = NULL;
	g_return_if_fail (self != NULL);
	g_message ("gzen_money.vala:134: Get credentials");
	_tmp0_ = gnome_keyring_attribute_list_new ();
	attributes = _tmp0_;
	_tmp1_ = attributes;
	gnome_keyring_attribute_list_append_string (_tmp1_, "application", APP_NAME);
	search_result = NULL;
	_tmp2_ = attributes;
	gnome_keyring_find_items_sync (GNOME_KEYRING_ITEM_NETWORK_PASSWORD, _tmp2_, &_tmp3_);
	__g_list_free___vala_GnomeKeyringFound_free0_0 (search_result);
	search_result = _tmp3_;
	_tmp4_ = g_strdup ("");
	secret = _tmp4_;
	_tmp5_ = search_result;
	{
		GList* Item_collection = NULL;
		GList* Item_it = NULL;
		Item_collection = _tmp5_;
		for (Item_it = Item_collection; Item_it != NULL; Item_it = Item_it->next) {
			GnomeKeyringFound* _tmp6_ = NULL;
			GnomeKeyringFound* Item = NULL;
			_tmp6_ = __vala_GnomeKeyringFound_copy0 ((GnomeKeyringFound*) Item_it->data);
			Item = _tmp6_;
			{
				GnomeKeyringFound* _tmp7_ = NULL;
				const gchar* _tmp8_ = NULL;
				gchar* _tmp9_ = NULL;
				GnomeKeyringFound* _tmp10_ = NULL;
				const gchar* _tmp11_ = NULL;
				GnomeKeyringFound* _tmp12_ = NULL;
				guint _tmp13_ = 0U;
				gchar* _tmp14_ = NULL;
				gchar* _tmp15_ = NULL;
				_tmp7_ = Item;
				_tmp8_ = _tmp7_->secret;
				_tmp9_ = g_strdup (_tmp8_);
				_g_free0 (secret);
				secret = _tmp9_;
				_tmp10_ = Item;
				_tmp11_ = _tmp10_->secret;
				g_message ("gzen_money.vala:145: %s", _tmp11_);
				_tmp12_ = Item;
				_tmp13_ = _tmp12_->item_id;
				_tmp14_ = g_strdup_printf ("%u", (guint) _tmp13_);
				_tmp15_ = _tmp14_;
				g_message ("gzen_money.vala:146: %s", _tmp15_);
				_g_free0 (_tmp15_);
				__vala_GnomeKeyringFound_free0 (Item);
			}
		}
	}
	_tmp16_ = self->priv->zenmoney;
	_tmp17_ = secret;
	zenmoney_init (_tmp16_, "215923621d51fb49f10b0a98bc579f", _tmp17_);
	g_message ("gzen_money.vala:150: Loading home");
	_tmp18_ = self->priv->zenmoney;
	_tmp19_ = zenmoney_home_timeline (_tmp18_);
	_tmp20_ = _tmp19_;
	_g_object_unref0 (_tmp20_);
	g_message ("gzen_money.vala:152: Home loaded");
	_g_free0 (secret);
	__g_list_free___vala_GnomeKeyringFound_free0_0 (search_result);
	_g_array_unref0 (attributes);
}


static void main_saveCredentials (Main* self, GeeMap* secret) {
	GnomeKeyringAttributeList* attributes = NULL;
	GnomeKeyringAttributeList* _tmp0_ = NULL;
	GeeMap* _tmp1_ = NULL;
	gpointer _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	guint32 item_id = 0U;
	GeeMap* _tmp4_ = NULL;
	gpointer _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	guint32 _tmp7_ = 0U;
	g_return_if_fail (self != NULL);
	g_return_if_fail (secret != NULL);
	gnome_keyring_create_sync (APP_NAME, "wattapas");
	_tmp0_ = gnome_keyring_attribute_list_new ();
	attributes = _tmp0_;
	gnome_keyring_attribute_list_append_string (attributes, "application", APP_NAME);
	_tmp1_ = secret;
	_tmp2_ = gee_map_get (_tmp1_, "consumer_key");
	_tmp3_ = (gchar*) _tmp2_;
	gnome_keyring_attribute_list_append_string (attributes, "consumer_key", _tmp3_);
	_g_free0 (_tmp3_);
	item_id = (guint32) 0;
	_tmp4_ = secret;
	_tmp5_ = gee_map_get (_tmp4_, "consumer_secret");
	_tmp6_ = (gchar*) _tmp5_;
	gnome_keyring_item_create_sync (APP_NAME, GNOME_KEYRING_ITEM_NETWORK_PASSWORD, "Gzen-money keyring", attributes, _tmp6_, TRUE, &_tmp7_);
	item_id = _tmp7_;
	_g_free0 (_tmp6_);
	_g_array_unref0 (attributes);
}


static gint main_main (gchar** args, int args_length1) {
	gint result = 0;
	Main* app = NULL;
	Main* _tmp0_ = NULL;
	g_message ("gzen_money.vala:167: Starting main loop");
	gtk_init (&args_length1, &args);
	_tmp0_ = main_new ();
	app = _tmp0_;
	gtk_main ();
	result = 0;
	_g_object_unref0 (app);
	return result;
}


int main (int argc, char ** argv) {
#if !GLIB_CHECK_VERSION (2,35,0)
	g_type_init ();
#endif
	return main_main (argv, argc);
}


static void main_class_init (MainClass * klass) {
	main_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (MainPrivate));
	G_OBJECT_CLASS (klass)->finalize = main_finalize;
}


static void main_instance_init (Main * self) {
	self->priv = MAIN_GET_PRIVATE (self);
}


static void main_finalize (GObject* obj) {
	Main * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_MAIN, Main);
	_g_object_unref0 (self->priv->login_button);
	_zenmoney_unref0 (self->priv->zenmoney);
	_g_object_unref0 (self->priv->dbus_server);
	G_OBJECT_CLASS (main_parent_class)->finalize (obj);
}


GType main_get_type (void) {
	static volatile gsize main_type_id__volatile = 0;
	if (g_once_init_enter (&main_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Main), 0, (GInstanceInitFunc) main_instance_init, NULL };
		GType main_type_id;
		main_type_id = g_type_register_static (G_TYPE_OBJECT, "Main", &g_define_type_info, 0);
		g_once_init_leave (&main_type_id__volatile, main_type_id);
	}
	return main_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



