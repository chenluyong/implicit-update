#ifndef OELIB_UPDATE_GLOBAL_H
#define OELIB_UPDATE_GLOBAL_H

#include "update_define.h"

#if defined(OEUPDATE_LIBRARY)
#  define OEUPDATESHARED_EXPORT __declspec(dllexport)
#else
#  define OEUPDATESHARED_EXPORT __declspec(dllimport)
#endif

#define OE_VERSION(a,b,c,d) ((a << 24) + (b << 16) + (c << 8) + d)

#ifndef Q_DECLARE_PRIVATE
#define Q_DECLARE_PRIVATE(Class) \
    inline Class##Private* d_func() { return reinterpret_cast<Class##Private *>(d_ptr); } \
    inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private *>(d_ptr); } \
    friend class Class##Private;
#endif

#ifndef Q_DECLARE_PUBLIC
#define Q_DECLARE_PUBLIC(Class)                                    \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;
#endif

#ifndef Q_D
#define Q_D(Class) Class##Private * const d = d_func()
#endif
#ifndef Q_Q
#define Q_Q(Class) Class * q = q_func()
#endif


#endif // OELIB_UPDATE_GLOBAL_H
