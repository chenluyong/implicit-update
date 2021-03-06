#ifndef OELIB_UPDATE_DEFINE_H
#define OELIB_UPDATE_DEFINE_H


/// @brief : return code
///
#define OELIB_SUCCESS                   (0)         // success code
#define OELIB_ERROR                     (-1)        // unknown error

#define OELIB_ERROR_HIGHEST_VERSION     (-1000)     // latest version


#define STD_ERROR_PARAM_ERROR           (87)        // The param is unqualified

#define STD_ERROR_NETWORK_CLOSED        (1226)      // The network connection has been closed and disconnected.
#define STD_ERROR_NETWORK_CONNECTED     (1227)      // The network is connected

#define STD_ERROR_TYPE                  (1629)      // The datatype unqualified
#define STD_ERROR_NETWORK_DOWNLOAD_FILE (1706)      // Not a valid download file.


/// @brief : dll version
#define OE_VERSION(a,b,c,d) ((a << 24) + (b << 16) + (c << 8) + d)

#define OELIB_CALLBACK

#define OELIB_DEBUG (5)


#endif // OELIB_UPDATE_DEFINE_H
