// Auto-generated. Do not edit!

// (in-package supervisor.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class imgData {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.upperleft = null;
      this.lowerRight = null;
      this.color = null;
      this.cameraID = null;
    }
    else {
      if (initObj.hasOwnProperty('upperleft')) {
        this.upperleft = initObj.upperleft
      }
      else {
        this.upperleft = 0;
      }
      if (initObj.hasOwnProperty('lowerRight')) {
        this.lowerRight = initObj.lowerRight
      }
      else {
        this.lowerRight = 0;
      }
      if (initObj.hasOwnProperty('color')) {
        this.color = initObj.color
      }
      else {
        this.color = '';
      }
      if (initObj.hasOwnProperty('cameraID')) {
        this.cameraID = initObj.cameraID
      }
      else {
        this.cameraID = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type imgData
    // Serialize message field [upperleft]
    bufferOffset = _serializer.int32(obj.upperleft, buffer, bufferOffset);
    // Serialize message field [lowerRight]
    bufferOffset = _serializer.int32(obj.lowerRight, buffer, bufferOffset);
    // Serialize message field [color]
    bufferOffset = _serializer.string(obj.color, buffer, bufferOffset);
    // Serialize message field [cameraID]
    bufferOffset = _serializer.string(obj.cameraID, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type imgData
    let len;
    let data = new imgData(null);
    // Deserialize message field [upperleft]
    data.upperleft = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [lowerRight]
    data.lowerRight = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [color]
    data.color = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [cameraID]
    data.cameraID = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.color.length;
    length += object.cameraID.length;
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'supervisor/imgData';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '01ffaf0e26fa935372f1b74d92aa2818';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
      int32 upperleft
      int32 lowerRight
      string color
      string cameraID
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new imgData(null);
    if (msg.upperleft !== undefined) {
      resolved.upperleft = msg.upperleft;
    }
    else {
      resolved.upperleft = 0
    }

    if (msg.lowerRight !== undefined) {
      resolved.lowerRight = msg.lowerRight;
    }
    else {
      resolved.lowerRight = 0
    }

    if (msg.color !== undefined) {
      resolved.color = msg.color;
    }
    else {
      resolved.color = ''
    }

    if (msg.cameraID !== undefined) {
      resolved.cameraID = msg.cameraID;
    }
    else {
      resolved.cameraID = ''
    }

    return resolved;
    }
};

module.exports = imgData;
