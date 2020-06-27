;; Auto-generated. Do not edit!


(when (boundp 'supervisor::imgDataArray)
  (if (not (find-package "SUPERVISOR"))
    (make-package "SUPERVISOR"))
  (shadow 'imgDataArray (find-package "SUPERVISOR")))
(unless (find-package "SUPERVISOR::IMGDATAARRAY")
  (make-package "SUPERVISOR::IMGDATAARRAY"))

(in-package "ROS")
;;//! \htmlinclude imgDataArray.msg.html


(defclass supervisor::imgDataArray
  :super ros::object
  :slots (_images ))

(defmethod supervisor::imgDataArray
  (:init
   (&key
    ((:images __images) (let (r) (dotimes (i 0) (push (instance supervisor::imgData :init) r)) r))
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
    ;; supervisor/imgData[] _images
    (apply #'+ (send-all _images :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; supervisor/imgData[] _images
     (write-long (length _images) s)
     (dolist (elem _images)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; supervisor/imgData[] _images
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _images (let (r) (dotimes (i n) (push (instance supervisor::imgData :init) r)) r))
     (dolist (elem- _images)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get supervisor::imgDataArray :md5sum-) "7c469dcd5daa68d701dc4178cb80f86d")
(setf (get supervisor::imgDataArray :datatype-) "supervisor/imgDataArray")
(setf (get supervisor::imgDataArray :definition-)
      "imgData[] images
================================================================================
MSG: supervisor/imgData

  int32 upperleft
  int32 lowerRight
  string color
  string cameraID
")



(provide :supervisor/imgDataArray "7c469dcd5daa68d701dc4178cb80f86d")


