;; Auto-generated. Do not edit!


(when (boundp 'beginner_tutorials::Num)
  (if (not (find-package "BEGINNER_TUTORIALS"))
    (make-package "BEGINNER_TUTORIALS"))
  (shadow 'Num (find-package "BEGINNER_TUTORIALS")))
(unless (find-package "BEGINNER_TUTORIALS::NUM")
  (make-package "BEGINNER_TUTORIALS::NUM"))

(in-package "ROS")
;;//! \htmlinclude Num.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass beginner_tutorials::Num
  :super ros::object
  :slots (_header _num _no _idade _score ))

(defmethod beginner_tutorials::Num
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:num __num) 0)
    ((:no __no) "")
    ((:idade __idade) 0)
    ((:score __score) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _num (round __num))
   (setq _no (string __no))
   (setq _idade (round __idade))
   (setq _score (round __score))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:num
   (&optional __num)
   (if __num (setq _num __num)) _num)
  (:no
   (&optional __no)
   (if __no (setq _no __no)) _no)
  (:idade
   (&optional __idade)
   (if __idade (setq _idade __idade)) _idade)
  (:score
   (&optional __score)
   (if __score (setq _score __score)) _score)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int8 _num
    1
    ;; string _no
    4 (length _no)
    ;; uint8 _idade
    1
    ;; uint32 _score
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int8 _num
       (write-byte _num s)
     ;; string _no
       (write-long (length _no) s) (princ _no s)
     ;; uint8 _idade
       (write-byte _idade s)
     ;; uint32 _score
       (write-long _score s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int8 _num
     (setq _num (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _num 127) (setq _num (- _num 256)))
   ;; string _no
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _no (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _idade
     (setq _idade (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint32 _score
     (setq _score (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get beginner_tutorials::Num :md5sum-) "4c72fae36a46f0a4fd2ae56297d39682")
(setf (get beginner_tutorials::Num :datatype-) "beginner_tutorials/Num")
(setf (get beginner_tutorials::Num :definition-)
      "Header header
int8 num
string no
uint8 idade
uint32 score

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :beginner_tutorials/Num "4c72fae36a46f0a4fd2ae56297d39682")


