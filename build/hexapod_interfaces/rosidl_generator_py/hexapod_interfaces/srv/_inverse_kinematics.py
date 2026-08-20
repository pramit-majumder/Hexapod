# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hexapod_interfaces:srv/InverseKinematics.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_InverseKinematics_Request(type):
    """Metaclass of message 'InverseKinematics_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hexapod_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hexapod_interfaces.srv.InverseKinematics_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__inverse_kinematics__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__inverse_kinematics__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__inverse_kinematics__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__inverse_kinematics__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__inverse_kinematics__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class InverseKinematics_Request(metaclass=Metaclass_InverseKinematics_Request):
    """Message class 'InverseKinematics_Request'."""

    __slots__ = [
        '_x',
        '_y',
        '_z',
        '_coxa_length',
        '_femur_length',
        '_tibia_length',
    ]

    _fields_and_field_types = {
        'x': 'int64',
        'y': 'int64',
        'z': 'int64',
        'coxa_length': 'int64',
        'femur_length': 'int64',
        'tibia_length': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x = kwargs.get('x', int())
        self.y = kwargs.get('y', int())
        self.z = kwargs.get('z', int())
        self.coxa_length = kwargs.get('coxa_length', int())
        self.femur_length = kwargs.get('femur_length', int())
        self.tibia_length = kwargs.get('tibia_length', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.z != other.z:
            return False
        if self.coxa_length != other.coxa_length:
            return False
        if self.femur_length != other.femur_length:
            return False
        if self.tibia_length != other.tibia_length:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'x' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'x' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'y' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._y = value

    @builtins.property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'z' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'z' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._z = value

    @builtins.property
    def coxa_length(self):
        """Message field 'coxa_length'."""
        return self._coxa_length

    @coxa_length.setter
    def coxa_length(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'coxa_length' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'coxa_length' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._coxa_length = value

    @builtins.property
    def femur_length(self):
        """Message field 'femur_length'."""
        return self._femur_length

    @femur_length.setter
    def femur_length(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'femur_length' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'femur_length' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._femur_length = value

    @builtins.property
    def tibia_length(self):
        """Message field 'tibia_length'."""
        return self._tibia_length

    @tibia_length.setter
    def tibia_length(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tibia_length' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'tibia_length' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._tibia_length = value


# Import statements for member types

# already imported above
# import builtins

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_InverseKinematics_Response(type):
    """Metaclass of message 'InverseKinematics_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hexapod_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hexapod_interfaces.srv.InverseKinematics_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__inverse_kinematics__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__inverse_kinematics__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__inverse_kinematics__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__inverse_kinematics__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__inverse_kinematics__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class InverseKinematics_Response(metaclass=Metaclass_InverseKinematics_Response):
    """Message class 'InverseKinematics_Response'."""

    __slots__ = [
        '_coxa',
        '_femur',
        '_tibia',
    ]

    _fields_and_field_types = {
        'coxa': 'float',
        'femur': 'float',
        'tibia': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.coxa = kwargs.get('coxa', float())
        self.femur = kwargs.get('femur', float())
        self.tibia = kwargs.get('tibia', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.coxa != other.coxa:
            return False
        if self.femur != other.femur:
            return False
        if self.tibia != other.tibia:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def coxa(self):
        """Message field 'coxa'."""
        return self._coxa

    @coxa.setter
    def coxa(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'coxa' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'coxa' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._coxa = value

    @builtins.property
    def femur(self):
        """Message field 'femur'."""
        return self._femur

    @femur.setter
    def femur(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'femur' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'femur' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._femur = value

    @builtins.property
    def tibia(self):
        """Message field 'tibia'."""
        return self._tibia

    @tibia.setter
    def tibia(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tibia' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'tibia' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._tibia = value


class Metaclass_InverseKinematics(type):
    """Metaclass of service 'InverseKinematics'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hexapod_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hexapod_interfaces.srv.InverseKinematics')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__inverse_kinematics

            from hexapod_interfaces.srv import _inverse_kinematics
            if _inverse_kinematics.Metaclass_InverseKinematics_Request._TYPE_SUPPORT is None:
                _inverse_kinematics.Metaclass_InverseKinematics_Request.__import_type_support__()
            if _inverse_kinematics.Metaclass_InverseKinematics_Response._TYPE_SUPPORT is None:
                _inverse_kinematics.Metaclass_InverseKinematics_Response.__import_type_support__()


class InverseKinematics(metaclass=Metaclass_InverseKinematics):
    from hexapod_interfaces.srv._inverse_kinematics import InverseKinematics_Request as Request
    from hexapod_interfaces.srv._inverse_kinematics import InverseKinematics_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
