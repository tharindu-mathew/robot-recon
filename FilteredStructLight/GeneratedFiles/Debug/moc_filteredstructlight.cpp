/****************************************************************************
** Meta object code from reading C++ file 'filteredstructlight.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../filteredstructlight.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filteredstructlight.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QArrayPushButton_t {
    QByteArrayData data[5];
    char stringdata[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QArrayPushButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QArrayPushButton_t qt_meta_stringdata_QArrayPushButton = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 15),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 2),
QT_MOC_LITERAL(4, 37, 17)
    },
    "QArrayPushButton\0clicked_with_id\0\0id\0"
    "intercept_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QArrayPushButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QArrayPushButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QArrayPushButton *_t = static_cast<QArrayPushButton *>(_o);
        switch (_id) {
        case 0: _t->clicked_with_id((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->intercept_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QArrayPushButton::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QArrayPushButton::clicked_with_id)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QArrayPushButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_QArrayPushButton.data,
      qt_meta_data_QArrayPushButton,  qt_static_metacall, 0, 0}
};


const QMetaObject *QArrayPushButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QArrayPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QArrayPushButton.stringdata))
        return static_cast<void*>(const_cast< QArrayPushButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int QArrayPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QArrayPushButton::clicked_with_id(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QArrayRadioButton_t {
    QByteArrayData data[5];
    char stringdata[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QArrayRadioButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QArrayRadioButton_t qt_meta_stringdata_QArrayRadioButton = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 15),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 2),
QT_MOC_LITERAL(4, 38, 17)
    },
    "QArrayRadioButton\0clicked_with_id\0\0"
    "id\0intercept_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QArrayRadioButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QArrayRadioButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QArrayRadioButton *_t = static_cast<QArrayRadioButton *>(_o);
        switch (_id) {
        case 0: _t->clicked_with_id((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->intercept_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QArrayRadioButton::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QArrayRadioButton::clicked_with_id)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QArrayRadioButton::staticMetaObject = {
    { &QRadioButton::staticMetaObject, qt_meta_stringdata_QArrayRadioButton.data,
      qt_meta_data_QArrayRadioButton,  qt_static_metacall, 0, 0}
};


const QMetaObject *QArrayRadioButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QArrayRadioButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QArrayRadioButton.stringdata))
        return static_cast<void*>(const_cast< QArrayRadioButton*>(this));
    return QRadioButton::qt_metacast(_clname);
}

int QArrayRadioButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QRadioButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QArrayRadioButton::clicked_with_id(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FilteredStructLight_t {
    QByteArrayData data[25];
    char stringdata[430];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilteredStructLight_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilteredStructLight_t qt_meta_stringdata_FilteredStructLight = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 13),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 8),
QT_MOC_LITERAL(4, 44, 19),
QT_MOC_LITERAL(5, 64, 19),
QT_MOC_LITERAL(6, 84, 19),
QT_MOC_LITERAL(7, 104, 19),
QT_MOC_LITERAL(8, 124, 27),
QT_MOC_LITERAL(9, 152, 18),
QT_MOC_LITERAL(10, 171, 26),
QT_MOC_LITERAL(11, 198, 26),
QT_MOC_LITERAL(12, 225, 29),
QT_MOC_LITERAL(13, 255, 22),
QT_MOC_LITERAL(14, 278, 24),
QT_MOC_LITERAL(15, 303, 10),
QT_MOC_LITERAL(16, 314, 22),
QT_MOC_LITERAL(17, 337, 5),
QT_MOC_LITERAL(18, 343, 15),
QT_MOC_LITERAL(19, 359, 8),
QT_MOC_LITERAL(20, 368, 18),
QT_MOC_LITERAL(21, 387, 9),
QT_MOC_LITERAL(22, 397, 14),
QT_MOC_LITERAL(23, 412, 7),
QT_MOC_LITERAL(24, 420, 9)
    },
    "FilteredStructLight\0update_images\0\0"
    "frame_no\0save_recon_settings\0"
    "save_swarm_settings\0swarm_conf_filepath\0"
    "load_swarm_settings\0populate_opt_params_from_ui\0"
    "OptimizationParams\0load_swarm_config_settings\0"
    "save_swarm_config_settings\0"
    "start_reconstruction_sequence\0"
    "handle_frame_filenames\0std::vector<std::string>\0"
    "image_list\0update_time_step_count\0"
    "count\0update_sampling\0sampling\0"
    "update_sim_results\0timesteps\0"
    "multi_sampling\0density\0occlusion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilteredStructLight[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    0,   77,    2, 0x08 /* Private */,
       5,    1,   78,    2, 0x08 /* Private */,
       7,    1,   81,    2, 0x08 /* Private */,
       8,    0,   84,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    1,   88,    2, 0x0a /* Public */,
      16,    1,   91,    2, 0x0a /* Public */,
      18,    1,   94,    2, 0x0a /* Public */,
      20,    4,   97,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    0x80000000 | 9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   21,   22,   23,   24,

       0        // eod
};

void FilteredStructLight::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilteredStructLight *_t = static_cast<FilteredStructLight *>(_o);
        switch (_id) {
        case 0: _t->update_images((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->save_recon_settings(); break;
        case 2: _t->save_swarm_settings((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->load_swarm_settings((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: { OptimizationParams _r = _t->get_opt_params_from_ui();
            if (_a[0]) *reinterpret_cast< OptimizationParams*>(_a[0]) = _r; }  break;
        case 5: _t->load_swarm_config_settings(); break;
        case 6: _t->save_swarm_config_settings(); break;
        case 7: _t->start_reconstruction_sequence(); break;
        case 8: _t->handle_frame_filenames((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 9: _t->update_time_step_count((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->update_sampling((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->update_sim_results((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObject FilteredStructLight::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FilteredStructLight.data,
      qt_meta_data_FilteredStructLight,  qt_static_metacall, 0, 0}
};


const QMetaObject *FilteredStructLight::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilteredStructLight::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FilteredStructLight.stringdata))
        return static_cast<void*>(const_cast< FilteredStructLight*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FilteredStructLight::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
