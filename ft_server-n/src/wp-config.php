<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'admin' ); 

/** MySQL database password */
define( 'DB_PASSWORD', '1111' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'W9#;+/=2FM QC:!PkGXPAV|/zYEoR<xTnUY q<zjVZr,!D=i5]Ax.1oX%6;-Vx]h');
define('SECURE_AUTH_KEY',  'gG$%x*B]#]q:/2_J+oaVEvY+bR:yO-{N!hTdC?|!U-ur{J*+:U)@IbYdFdXd4ng7');
define('LOGGED_IN_KEY',    'Z$J1(;equ4T&rW7< 5X|bmm*]>YBz+^DXvkvo*4BAB|ZOFE%4&nBAV[.EO}b`5^Y');
define('NONCE_KEY',        'ApxGq>:tmJVwH+0t@%KSI^#YI?`obZ<)GRd;zEV5R#n*&P0^}-10PB|~K#fRnb+<');
define('AUTH_SALT',        'JTsc(z~qraube%F+N>AdRF]<LaS:s6%A5g03DS?-=E|F_5aoA!|`:|DS}3M{l5c&');
define('SECURE_AUTH_SALT', 'Gh4Rf-JmJCFexrDDZ+mqFA|*dE/O|H<GDJ|.Z@t[;:4A5o$Y9p/E,~(.a&Pw_,b7');
define('LOGGED_IN_SALT',   'j1Z_5dh$]Nj]sN!j=1jBWZNsRB<_?C-LDG|^+c/c-Al `,-LFyx@ n-f2IA@Im0<');
define('NONCE_SALT',       'yNr7KRF3Z3<!F&Dz*?}gEXa*/+CU{DovpR>VHV]Gq$-~ln+Rv)>EUeR19P$3{qIP');
/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
