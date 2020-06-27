; Auto-generated. Do not edit!


(cl:in-package supervisor-msg)


;//! \htmlinclude planoArray.msg.html

(cl:defclass <planoArray> (roslisp-msg-protocol:ros-message)
  ((images
    :reader images
    :initarg :images
    :type (cl:vector supervisor-msg:plano)
   :initform (cl:make-array 0 :element-type 'supervisor-msg:plano :initial-element (cl:make-instance 'supervisor-msg:plano))))
)

(cl:defclass planoArray (<planoArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <planoArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'planoArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name supervisor-msg:<planoArray> is deprecated: use supervisor-msg:planoArray instead.")))

(cl:ensure-generic-function 'images-val :lambda-list '(m))
(cl:defmethod images-val ((m <planoArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader supervisor-msg:images-val is deprecated.  Use supervisor-msg:images instead.")
  (images m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <planoArray>) ostream)
  "Serializes a message object of type '<planoArray>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'images))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'images))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <planoArray>) istream)
  "Deserializes a message object of type '<planoArray>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'images) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'images)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'supervisor-msg:plano))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<planoArray>)))
  "Returns string type for a message object of type '<planoArray>"
  "supervisor/planoArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'planoArray)))
  "Returns string type for a message object of type 'planoArray"
  "supervisor/planoArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<planoArray>)))
  "Returns md5sum for a message object of type '<planoArray>"
  "7c469dcd5daa68d701dc4178cb80f86d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'planoArray)))
  "Returns md5sum for a message object of type 'planoArray"
  "7c469dcd5daa68d701dc4178cb80f86d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<planoArray>)))
  "Returns full string definition for message of type '<planoArray>"
  (cl:format cl:nil "plano[] images~%================================================================================~%MSG: supervisor/plano~%~%  int32 upperleft~%  int32 lowerRight~%  string color~%  string cameraID~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'planoArray)))
  "Returns full string definition for message of type 'planoArray"
  (cl:format cl:nil "plano[] images~%================================================================================~%MSG: supervisor/plano~%~%  int32 upperleft~%  int32 lowerRight~%  string color~%  string cameraID~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <planoArray>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'images) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <planoArray>))
  "Converts a ROS message object to a list"
  (cl:list 'planoArray
    (cl:cons ':images (images msg))
))
