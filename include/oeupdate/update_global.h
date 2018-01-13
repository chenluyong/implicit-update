#ifndef OELIB_UPDATE_GLOBAL_H
#define OELIB_UPDATE_GLOBAL_H

#include "update_define.h"

#if defined(OEUPDATE_LIBRARY)
#  define OEUPDATESHARED_EXPORT __declspec(dllexport)
#else
#  define OEUPDATESHARED_EXPORT __declspec(dllimport)
#endif


#ifndef Q_DECLARE_PRIVATE
#define Q_DECLARE_PRIVATE(Class) \
    inline Class##Private* d_func() { return reinterpret_cast<Class##Private *>(d_ptr); } \
    inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private *>(d_ptr); } \
    friend class Class##Private;
#endif // !Q_DECLARE_PRIVATE

#ifndef Q_DECLARE_PUBLIC
#define Q_DECLARE_PUBLIC(Class)                                    \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;
#endif // !Q_DECLARE_PUBLIC

#ifndef Q_D
#define Q_D(Class) Class##Private * const d = d_func()
#endif // !Q_D
#ifndef Q_Q
#define Q_Q(Class) Class * q = q_func()
#endif // !Q_Q

#ifndef NULL
#define NULL 0
#endif // !NULL


#endif // OELIB_UPDATE_GLOBAL_H
