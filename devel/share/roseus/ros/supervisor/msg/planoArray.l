;; Auto-generated. Do not edit!


(when (boundp 'supervisor::planoArray)
  (if (not (find-package "SUPERVISOR"))
    (make-package "SUPERVISOR"))
  (shadow 'planoArray (find-package "SUPERVISOR")))
(unless (find-package "SUPERVISOR::PLANOARRAY")
  (make-package "SUPERVISOR::PLANOARRAY"))

(in-package "ROS")
;;//! \htmlinclude planoArray.msg.html


(defclass supervisor::planoArray
  :super ros::object
  :slots (_images ))

(defmethod supervisor::planoArray
  (:init
   (&key
    ((:images __images) (let (r) (dotimes (i 0) (push (instance supervisor::plano :init) r)) r))
    )
   (send-super :init)
   (setq _images __images)
   self)
  (:images
   (&rest __images)
   (if (keywordp (car __images))
       (send* _images __images)
     (progn
       (if __images (setq _images (car __images)))
       _images)))
  (:serialization-length
   ()
   (+
    ;; supervisor/plano[] _images
    (apply #'+ (send-all _images :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; supervisor/plano[] _images
     (write-long (length _images) s)
     (dolist (elem _images)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; supervisor/plano[] _images
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _images (let (r) (dotimes (i n) (push (instance supervisor::plano :init) r)) r))
     (dolist (elem- _images)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get supervisor::planoArray :md5sum-) "7c469dcd5daa68d701dc4178cb80f86d")
(setf (get supervisor::planoArray :datatype-) "supervisor/planoArray")
(setf (get supervisor::planoArray :definition-)
      "plano[] images
================================================================================
MSG: supervisor/plano

  int32 upperleft
  int32 lowerRight
  string color
  string cameraID
")



(provide :supervisor/planoArray "7c469dcd5daa68d701dc4178cb80f86d")


