// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hexapod_interfaces:srv/InverseKinematics.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "hexapod_interfaces/srv/detail/inverse_kinematics__struct.h"
#include "hexapod_interfaces/srv/detail/inverse_kinematics__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hexapod_interfaces__srv__inverse_kinematics__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[69];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("hexapod_interfaces.srv._inverse_kinematics.InverseKinematics_Request", full_classname_dest, 68) == 0);
  }
  hexapod_interfaces__srv__InverseKinematics_Request * ros_message = _ros_message;
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->x = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->y = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // z
    PyObject * field = PyObject_GetAttrString(_pymsg, "z");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->z = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // coxa_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "coxa_length");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->coxa_length = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // femur_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "femur_length");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->femur_length = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // tibia_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "tibia_length");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->tibia_length = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hexapod_interfaces__srv__inverse_kinematics__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of InverseKinematics_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hexapod_interfaces.srv._inverse_kinematics");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "InverseKinematics_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hexapod_interfaces__srv__InverseKinematics_Request * ros_message = (hexapod_interfaces__srv__InverseKinematics_Request *)raw_ros_message;
  {  // x
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // coxa_length
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->coxa_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "coxa_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // femur_length
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->femur_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "femur_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tibia_length
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->tibia_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tibia_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "hexapod_interfaces/srv/detail/inverse_kinematics__struct.h"
// already included above
// #include "hexapod_interfaces/srv/detail/inverse_kinematics__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hexapod_interfaces__srv__inverse_kinematics__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[70];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("hexapod_interfaces.srv._inverse_kinematics.InverseKinematics_Response", full_classname_dest, 69) == 0);
  }
  hexapod_interfaces__srv__InverseKinematics_Response * ros_message = _ros_message;
  {  // coxa
    PyObject * field = PyObject_GetAttrString(_pymsg, "coxa");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->coxa = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // femur
    PyObject * field = PyObject_GetAttrString(_pymsg, "femur");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->femur = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tibia
    PyObject * field = PyObject_GetAttrString(_pymsg, "tibia");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tibia = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hexapod_interfaces__srv__inverse_kinematics__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of InverseKinematics_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hexapod_interfaces.srv._inverse_kinematics");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "InverseKinematics_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hexapod_interfaces__srv__InverseKinematics_Response * ros_message = (hexapod_interfaces__srv__InverseKinematics_Response *)raw_ros_message;
  {  // coxa
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->coxa);
    {
      int rc = PyObject_SetAttrString(_pymessage, "coxa", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // femur
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->femur);
    {
      int rc = PyObject_SetAttrString(_pymessage, "femur", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tibia
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tibia);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tibia", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
