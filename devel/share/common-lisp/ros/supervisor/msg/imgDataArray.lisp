; Auto-generated. Do not edit!


(cl:in-package supervisor-msg)


;//! \htmlinclude imgDataArray.msg.html

(cl:defclass <imgDataArray> (roslisp-msg-protocol:ros-message)
  ((images
    :reader images
    :initarg :images
    :type (cl:vector supervisor-msg:imgData)
   :initform (cl:make-array 0 :element-type 'supervisor-msg:imgData :initial-element (cl:make-instance 'supervisor-msg:imgData))))
)

(cl:defclass imgDataArray (<imgDataArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <imgDataArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'imgDataArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name supervisor-msg:<imgDataArray> is deprecated: use supervisor-msg:imgDataArray instead.")))

(cl:ensure-generic-function 'images-val :lambda-list '(m))
(cl:defmethod images-val ((m <imgDataArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader supervisor-msg:images-val is deprecated.  Use supervisor-msg:images instead.")
  (images m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <imgDataArray>) ostream)
  "Serializes a message object of type '<imgDataArray>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'images))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'images))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <imgDataArray>) istream)
  "Deserializes a message object of type '<imgDataArray>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'images) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'images)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'supervisor-msg:imgData))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<imgDataArray>)))
  "Returns string type for a message object of type '<imgDataArray>"
  "supervisor/imgDataArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'imgDataArray)))
  "Returns string type for a message object of type 'imgDataArray"
  "supervisor/imgDataArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<imgDataArray>)))
  "Returns md5sum for a message object of type '<imgDataArray>"
  "7c469dcd5daa68d701dc4178cb80f86d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'imgDataArray)))
  "Returns md5sum for a message object of type 'imgDataArray"
  "7c469dcd5daa68d701dc4178cb80f86d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<imgDataArray>)))
  "Returns full string definition for message of type '<imgDataArray>"
  (cl:format cl:nil "imgData[] images~%================================================================================~%MSG: supervisor/imgData~%~%  int32 upperleft~%  int32 lowerRight~%  string color~%  string cameraID~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'imgDataArray)))
  "Returns full string definition for message of type 'imgDataArray"
  (cl:format cl:nil "imgData[] images~%================================================================================~%MSG: supervisor/imgData~%~%  int32 upperleft~%  int32 lowerRight~%  string color~%  string cameraID~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <imgDataArray>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'images) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <imgDataArray>))
  "Converts a ROS message object to a list"
  (cl:list 'imgDataArray
    (cl:cons ':images (images msg))
))
