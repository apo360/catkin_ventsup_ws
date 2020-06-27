// Generated by gencpp from file supervisor/planoArray.msg
// DO NOT EDIT!


#ifndef SUPERVISOR_MESSAGE_PLANOARRAY_H
#define SUPERVISOR_MESSAGE_PLANOARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <supervisor/plano.h>

namespace supervisor
{
template <class ContainerAllocator>
struct planoArray_
{
  typedef planoArray_<ContainerAllocator> Type;

  planoArray_()
    : images()  {
    }
  planoArray_(const ContainerAllocator& _alloc)
    : images(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::supervisor::plano_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::supervisor::plano_<ContainerAllocator> >::other >  _images_type;
  _images_type images;





  typedef boost::shared_ptr< ::supervisor::planoArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::supervisor::planoArray_<ContainerAllocator> const> ConstPtr;

}; // struct planoArray_

typedef ::supervisor::planoArray_<std::allocator<void> > planoArray;

typedef boost::shared_ptr< ::supervisor::planoArray > planoArrayPtr;
typedef boost::shared_ptr< ::supervisor::planoArray const> planoArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::supervisor::planoArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::supervisor::planoArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::supervisor::planoArray_<ContainerAllocator1> & lhs, const ::supervisor::planoArray_<ContainerAllocator2> & rhs)
{
  return lhs.images == rhs.images;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::supervisor::planoArray_<ContainerAllocator1> & lhs, const ::supervisor::planoArray_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace supervisor

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::supervisor::planoArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::supervisor::planoArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::supervisor::planoArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::supervisor::planoArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::supervisor::planoArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::supervisor::planoArray_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::supervisor::planoArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7c469dcd5daa68d701dc4178cb80f86d";
  }

  static const char* value(const ::supervisor::planoArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7c469dcd5daa68d7ULL;
  static const uint64_t static_value2 = 0x01dc4178cb80f86dULL;
};

template<class ContainerAllocator>
struct DataType< ::supervisor::planoArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "supervisor/planoArray";
  }

  static const char* value(const ::supervisor::planoArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::supervisor::planoArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "plano[] images\n"
"================================================================================\n"
"MSG: supervisor/plano\n"
"\n"
"  int32 upperleft\n"
"  int32 lowerRight\n"
"  string color\n"
"  string cameraID\n"
;
  }

  static const char* value(const ::supervisor::planoArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::supervisor::planoArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.images);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct planoArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::supervisor::planoArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::supervisor::planoArray_<ContainerAllocator>& v)
  {
    s << indent << "images[]" << std::endl;
    for (size_t i = 0; i < v.images.size(); ++i)
    {
      s << indent << "  images[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::supervisor::plano_<ContainerAllocator> >::stream(s, indent + "    ", v.images[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SUPERVISOR_MESSAGE_PLANOARRAY_H