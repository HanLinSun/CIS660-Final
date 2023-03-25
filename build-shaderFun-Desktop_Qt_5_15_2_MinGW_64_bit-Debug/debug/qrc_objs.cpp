/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.15.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // D:/CIS660/CIS660-Final/basecode/objs/wahoo.obj
  
  
    // D:/CIS660/CIS660-Final/basecode/objs/cow.obj
  
  
  
static const unsigned char qt_resource_data[430501] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // objs
  0x0,0x4,
  0x0,0x7,0x59,0x13,
  0x0,0x6f,
  0x0,0x62,0x0,0x6a,0x0,0x73,
    // wahoo.obj
  0x0,0x9,
  0xf,0x62,0xaf,0x6a,
  0x0,0x77,
  0x0,0x61,0x0,0x68,0x0,0x6f,0x0,0x6f,0x0,0x2e,0x0,0x6f,0x0,0x62,0x0,0x6a,
    // cow.obj
  0x0,0x7,
  0xa,0x6a,0x55,0x4a,
  0x0,0x63,
  0x0,0x6f,0x0,0x77,0x0,0x2e,0x0,0x6f,0x0,0x62,0x0,0x6a,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/objs
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/objs/cow.obj
  0x0,0x0,0x0,0x26,0x0,0x1,0x0,0x0,0x0,0x1,0x0,0x2,0xfb,0x98,
0x0,0x0,0x1,0x86,0xd1,0x7a,0x33,0xac,
  // :/objs/wahoo.obj
  0x0,0x0,0x0,0xe,0x0,0x1,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x86,0xd1,0x7a,0x33,0xbc,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#if defined(__ELF__) || defined(__APPLE__)
static inline unsigned char qResourceFeatureZlib()
{
    extern const unsigned char qt_resourceFeatureZlib;
    return qt_resourceFeatureZlib;
}
#else
unsigned char qResourceFeatureZlib();
#endif

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_objs)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_objs)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_objs)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_objs)()
{
    int version = 3;
    version += QT_RCC_PREPEND_NAMESPACE(qResourceFeatureZlib());
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_objs)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_objs)(); }
   } dummy;
}
