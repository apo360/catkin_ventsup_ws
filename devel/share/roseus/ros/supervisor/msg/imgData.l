;; Auto-generated. Do not edit!


(when (boundp 'supervisor::imgData)
  (if (not (find-package "SUPERVISOR"))
    (make-package "SUPERVISOR"))
  (shadow 'imgData (find-package "SUPERVISOR")))
(unless (find-package "SUPERVISOR::IMGDATA")
  (make-package "SUPERVISOR::IMGDATA"))

(in-package "ROS")
;;//! \htmlinclude imgData.msg.html


(defclass supervisor::imgData
  :super ros::object
  :slots (_upperleft _lowerRight _color _cameraID ))

(defmethod supervisor::imgData
  (:init
   (&key
    ((:upperleft __upperleft) 0)
    ((:lowerRight __lowerRight) 0)
    ((:color __color) "")
    ((:cameraID __cameraID) "")
    )
   (send-super :init)
   (setq _upperleft (round __upperleft))
   (setq _lowerRight (round __lowerRight))
   (setq _color (string __color))
   (setq _cameraID (string __cameraID))
   self)
  (:upperleft
   (&optional __upperleft)
   (if __upperleft (setq _upperleft __upperleft)) _upperleft)
  (:lowerRight
   (&optional __lowerRight)
   (if __lowerRight (setq _lowerRight __lowerRight)) _lowerRight)
  (:color
   (&optional __color)
   (if __color (setq _color __color)) _color)
  (:cameraID
   (&optional __cameraID)
   (if __cameraID (setq _cameraID __cameraID)) _cameraID)
  (:serialization-length
   ()
   (+
    ;; int32 _upperleft
    4
    ;; int32 _lowerRight
    4
    ;; string _color
    4 (length _color)
    ;; string _cameraID
    4 (length _cameraID)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _upperleft
       (write-long _upperleft s)
     ;; int32 _lowerRight
       (write-long _lowerRight s)
     ;; string _color
       (write-long (length _color) s) (princ _color s)
     ;; string _cameraID
       (write-long (length _cameraID) s) (princ _cameraID s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _upperleft
     (setq _upperleft (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _lowerRight
     (setq _lowerRight (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _color
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _color (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _cameraID
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _cameraID (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get supervisor::imgData :md5sum-) "01ffaf0e26fa935372f1b74d92aa2818")
(setf (get supervisor::imgData :datatype-) "supervisor/imgData")
(setf (get supervisor::imgData :definition-)
      "
  int32 upperleft
  int32 lowerRight
  string color
  string cameraID
")



(provide :supervisor/imgData "01ffaf0e26fa935372f1b74d92aa2818")


