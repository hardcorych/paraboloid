/****************************************************************************
** Meta object code from reading C++ file 'surface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../surface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'surface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Surface_t {
    QByteArrayData data[14];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Surface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Surface_t qt_meta_stringdata_Surface = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Surface"
QT_MOC_LITERAL(1, 8, 18), // "CalculationIsEnded"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 28), // "osg::ref_ptr<osg::Vec3Array>"
QT_MOC_LITERAL(4, 57, 9), // "_vertices"
QT_MOC_LITERAL(5, 67, 8), // "_normals"
QT_MOC_LITERAL(6, 76, 4), // "SetA"
QT_MOC_LITERAL(7, 81, 2), // "_a"
QT_MOC_LITERAL(8, 84, 4), // "SetB"
QT_MOC_LITERAL(9, 89, 2), // "_b"
QT_MOC_LITERAL(10, 92, 4), // "SetT"
QT_MOC_LITERAL(11, 97, 2), // "_t"
QT_MOC_LITERAL(12, 100, 16), // "StartCalculation"
QT_MOC_LITERAL(13, 117, 15) // "StopCalculation"

    },
    "Surface\0CalculationIsEnded\0\0"
    "osg::ref_ptr<osg::Vec3Array>\0_vertices\0"
    "_normals\0SetA\0_a\0SetB\0_b\0SetT\0_t\0"
    "StartCalculation\0StopCalculation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Surface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   49,    2, 0x0a /* Public */,
       8,    1,   52,    2, 0x0a /* Public */,
      10,    1,   55,    2, 0x0a /* Public */,
      12,    0,   58,    2, 0x0a /* Public */,
      13,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Surface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Surface *_t = static_cast<Surface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CalculationIsEnded((*reinterpret_cast< osg::ref_ptr<osg::Vec3Array>(*)>(_a[1])),(*reinterpret_cast< osg::ref_ptr<osg::Vec3Array>(*)>(_a[2]))); break;
        case 1: _t->SetA((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->SetB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->SetT((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->StartCalculation(); break;
        case 5: _t->StopCalculation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< osg::ref_ptr<osg::Vec3Array> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Surface::*_t)(osg::ref_ptr<osg::Vec3Array> , osg::ref_ptr<osg::Vec3Array> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Surface::CalculationIsEnded)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Surface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Surface.data,
      qt_meta_data_Surface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Surface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Surface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Surface.stringdata0))
        return static_cast<void*>(const_cast< Surface*>(this));
    if (!strcmp(_clname, "osg::Group"))
        return static_cast< osg::Group*>(const_cast< Surface*>(this));
    return QObject::qt_metacast(_clname);
}

int Surface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Surface::CalculationIsEnded(osg::ref_ptr<osg::Vec3Array> _t1, osg::ref_ptr<osg::Vec3Array> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
