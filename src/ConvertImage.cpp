// -*- C++ -*-
/*!
 * @file  ConvertImage.cpp
 * @brief Convert Image Component
 * @date $Date$
 *
 * $Id$
 */

#include "ConvertImage.h"
#include "ImageDataConv.h"

// Module specification
// <rtc-template block="module_spec">
static const char* convertimage_spec[] =
  {
    "implementation_id", "ConvertImage",
    "type_name",         "ConvertImage",
    "description",       "Convert Image Component",
    "version",           "1.0.0",
    "vendor",            "Miyamoto Nobuhiko",
    "category",          "ImageProcessing",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.string_encode", "off",
    "conf.default.int_encode_quality", "75",
    // Widget
    "conf.__widget__.string_encode", "radio",
    "conf.__widget__.int_encode_quality", "spin",
    // Constraints
    "conf.__constraints__.string_encode", "(off,jpeg,png)",
    "conf.__constraints__.int_encode_quality", "1<=x<=100",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ConvertImage::ConvertImage(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_imageInIn("imageIn", m_imageIn),
    m_imageOutOut("imageOut", m_imageOut)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ConvertImage::~ConvertImage()
{
}



RTC::ReturnCode_t ConvertImage::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("imageIn", m_imageInIn);
  
  // Set OutPort buffer
  addOutPort("imageOut", m_imageOutOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("string_encode", m_string_encode, "off");
  bindParameter("int_encode_quality", m_int_encode_quality, "75");
  
  // </rtc-template>
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConvertImage::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConvertImage::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConvertImage::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ConvertImage::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConvertImage::onDeactivated(RTC::UniqueId ec_id)
{

	
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConvertImage::onExecute(RTC::UniqueId ec_id)
{
	if(m_imageInIn.isNew())
	{
		m_imageInIn.read();
			
				

		image = GetCameraImage(&m_imageIn);

			
		SetCameraImage(&m_imageOut, &image, m_string_encode, m_int_encode_quality);
		m_imageOutOut.write();
	}
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConvertImage::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConvertImage::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConvertImage::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConvertImage::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ConvertImage::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ConvertImageInit(RTC::Manager* manager)
  {
    coil::Properties profile(convertimage_spec);
    manager->registerFactory(profile,
                             RTC::Create<ConvertImage>,
                             RTC::Delete<ConvertImage>);
  }
  
};


