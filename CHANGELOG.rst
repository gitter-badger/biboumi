Version 4.0 - 2016-11-09
[========================

 - The separator between the IRC nickname and the IRC server is now '%'
   instead of '!'. This makes things simpler (only one separator to
   remember). The distinction between a JID referring to a channel and a JID
   refering to a nickname is based on the first character (# or & by
   default, but this can be customized by the server with the ISUPPORT
   extension).
 - Handle channel invitations in both directions.
 - Add support for `JID escaping <.http://www.xmpp.org/extensions/xep-0106.html>`.
 - Save all channel messages into the database, with an ad-hoc option to
   disable this feature.
 - When joining a room, biboumi sends an history of the most recents messages
   found in the database.
 - Channel history can be retrieved using Message Archive Management.
 - Result Set Management can be used to request only parts of the IRC channel
   list.

Version 3.0 - 2016-08-03
========================

 - Support multiple-nick sessions: a user can join an IRC channel behind
   one single nick, using multiple different clients, at the same time (as
   long as each client is using the same bare JID).
 - Database support for persistant per-user per-server configuration. Add
   `LiteSQL <https://dev.louiz.org/projects/litesql>` as an optional
   dependency.
 - Add ad-hoc commands that lets each user configure various things
 - Support an after-connect command that will be sent to the server
   just after the user gets connected to it.
 - Support the sending of a PASS command.
 - Lets the users configure their username and realname, if the
   realname_customization is set to true.
 - The remote TLS certificates are checked against the system’s trusted
   CAs, unless the user used the configuration option that ignores these
   checks.
 - Lets the user set a sha-1 hash to identify a server certificate that
   should always be trusted.
 - Add an outgoing_bind option.
 - Add an ad-hoc command to forcefully disconnect a user from one or
   more servers.
 - Let the user configure the incoming encoding of an IRC server (the
   default behaviour remains unchanged: check if it’s valid utf-8 and if
   not, decode as latin-1).
 - Support `multi-prefix <http://ircv3.net/specs/extensions/multi-prefix-3.1.html>`.
 - And of course, many bufixes.
 - Run unit tests and a test suite, build the RPM and check many things
   automatically using gitlab-ci.


Version 2.0 - 2015-05-29
========================

 - List channels on an IRC server through an XMPP disco items request
 - Let the user send any arbitrary raw IRC command by sending a
   message to the IRC server’s JID.
 - By default, look for the configuration file as per the XDG
   basedir spec.
 - Support PING requests in all directions.
 - Improve the way we forward received NOTICEs by remembering to
   which users we previously sent a private message.  This improves the
   user experience when talking to NickServ.
 - Support joining key-protected channels
 - Setting a participant's role/affiliation now results in a change of IRC
   mode, instead of being ignored.  Setting Toto's affiliation to admin is
   now equivalent to “/mode +o Toto”
 - Fix the reconnection to the XMPP server to try every 2 seconds
   instead of immediately. This avoid hogging resources for nothing
 - Asynchronously resolve domain names by optionally using the DNS
   library c-ares.
 - Add a reload add-hoc command, to reload biboumi's configuration
 - Add a fixed_irc_server option.  With this option enabled,
   biboumi can only connect to the one single IRC server configured

Version 1.1 - 2014-07-16
========================

 - Fix a segmentation fault when connecting to an IRC server using IPv6

Version 1.0 - 2014-07-12
========================

 - First stable release.
 - Mostly complete MUC to IRC, and IRC to MUC support
 - Complete handling of private messages
 - Full IRC modes support: setting any IRC mode, and receiving notifications
   for every mode change
 - Verbose connection status notifications
 - Conversion from IRC formatting to XHTML-im
 - Ad-hoc commands support
 - Basic TLS support: auto-accepts all certificates, no cipher
   configuration, no way to force usage of TLS (it is used only if
   available, clear connection is automatically used as a fallback)
 - IPv6 support
