; Auto-generated. Do not edit!


(cl:in-package supervisor-msg)


;//! \htmlinclude imgData.msg.html

(cl:defclass <imgData> (roslisp-msg-protocol:ros-message)
  ((upperleft
    :reader upperleft
    :initarg :upperleft
    :type cl:integer
    :initform 0)
   (lowerRight
    :reader lowerRight
    :initarg :lowerRight
    :type cl:integer
    :initform 0)
   (color
    :reader color
    :initarg :color
    :type cl:string
    :initform "")
   (cameraID
    :reader cameraID
    :initarg :cameraID
    :type cl:string
    :initform ""))
)

(cl:defclass imgData (<imgData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <imgData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'imgData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name supervisor-msg:<imgData> is deprecated: use supervisor-msg:imgData instead.")))

(cl:ensure-generic-function 'upperleft-val :lambda-list '(m))
(cl:defmethod upperleft-val ((m <imgData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader supervisor-msg:upperleft-val is deprecated.  Use supervisor-msg:upperleft instead.")
  (upperleft m))

(cl:ensure-generic-function 'lowerRight-val :lambda-list '(m))
(cl:defmethod lowerRight-val ((m <imgData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader supervisor-msg:lowerRight-val is deprecated.  Use supervisor-msg:lowerRight instead.")
  (lowerRight m))

(cl:ensure-generic-function 'color-val :lambda-list '(m))
(cl:defmethod color-val ((m <imgData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader supervisor-msg:color-val is deprecated.  Use supervisor-msg:color instead.")
  (color m))

(cl:ensure-generic-function 'cameraID-val :lambda-list '(m))
(cl:defmethod cameraID-val ((m <imgData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader supervisor-msg:cameraID-val is deprecated.  Use supervisor-msg:cameraID instead.")
  (cameraID m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <imgData>) ostream)
  "Serializes a message object of type '<imgData>"
  (cl:let* ((signed (cl:slot-value msg 'upperleft)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'lowerRight)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'color))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'color))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'cameraID))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'cameraID))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <imgData>) istream)
  "Deserializes a message object of type '<imgData>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'upperleft) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'lowerRight) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'color) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'color) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cameraID) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'cameraID) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<imgData>)))
  "Returns string type for a message object of type '<imgData>"
  "supervisor/imgData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'imgData)))
  "Returns string type for a message object of type 'imgData"
  "supervisor/imgData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<imgData>)))
  "Returns md5sum for a message object of type '<imgData>"
  "01ffaf0e26fa935372f1b74d92aa2818")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'imgData)))
  "Returns md5sum for a message object of type 'imgData"
  "01ffaf0e26fa935372f1b74d92aa2818")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<imgData>)))
  "Returns full string definition for message of type '<imgData>"
  (cl:format cl:nil "~%  int32 upperleft~%  int32 lowerRight~%  string color~%  string cameraID~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'imgData)))
  "Returns full string definition for message of type 'imgData"
  (cl:format cl:nil "~%  int32 upperleft~%  int32 lowerRight~%  string color~%  string cameraID~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <imgData>))
  (cl:+ 0
     4
     4
     4 (cl:length (cl:slot-value msg 'color))
     4 (cl:length (cl:slot-value msg 'cameraID))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <imgData>))
  "Converts a ROS message object to a list"
  (cl:list 'imgData
    (cl:cons ':upperleft (upperleft msg))
    (cl:cons ':lowerRight (lowerRight msg))
    (cl:cons ':color (color msg))
    (cl:cons ':cameraID (cameraID msg))
))
