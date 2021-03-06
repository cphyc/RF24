#include <boost/python.hpp>
#include "RF24.h"
using namespace boost::python;

BOOST_PYTHON_MODULE(RF24_lib)
{
  class_<RF24>("RF24", init<uint8_t, uint8_t, uint32_t>())
    .def(init<uint8_t, uint8_t >())
    .def("begin", &RF24::begin)
    .def("startListening", &RF24::startListening)
    .def("stopListening", &RF24::stopListening)
    .def("write", static_cast< bool (RF24::*)(const void*, uint8_t,const bool) >(&RF24::write))  
    .def("write", static_cast< bool (RF24::*)(const void*, uint8_t) >(&RF24::write))  
    .def("available", static_cast< bool (RF24::*)(void) >(&RF24::available))
    .def("available", static_cast< bool (RF24::*)(uint8_t*) >(&RF24::available))
    .def("read", &RF24::read)
    .def("openWritingPipe", static_cast < void (RF24::*)(const uint8_t*) > (&RF24::openWritingPipe))
    .def("openWritingPipe", static_cast < void (RF24::*)(const uint64_t) > (&RF24::openWritingPipe)) // depreciated
    .def("openReadingPipe", static_cast < void (RF24::*)(uint8_t, const uint8_t*) > (&RF24::openReadingPipe))
    .def("openReadingPipe", static_cast < void (RF24::*)(uint8_t, uint64_t) > (&RF24::openReadingPipe)) // depreciated
    .def("flush_tx", &RF24::flush_tx)
    .def("setRetries", &RF24::setRetries)
    .def("setChannel", &RF24::setChannel)
    .def("setPayloadSize", &RF24::setPayloadSize)
    .def("getPayloadSize", &RF24::getPayloadSize)
    .def("getDynamicPayloadSize", &RF24::getDynamicPayloadSize)
    .def("enableAckPayload", &RF24::enableAckPayload)
    .def("enableDynamicPayloads", &RF24::enableDynamicPayloads)
    .def("enableDynamicAck", &RF24::enableDynamicAck)
    .def("isPVariant", &RF24::isPVariant)
    .def("setAutoAck", static_cast < void (RF24::*)(uint8_t, bool) > (&RF24::setAutoAck))
    .def("setAutoAck", static_cast < void (RF24::*)(bool) > (&RF24::setAutoAck))
    .def("setPALevel", &RF24::setPALevel)
    .def("getPALevel", &RF24::getPALevel)
    .def("setDataRate", &RF24::setDataRate)
    .def("getDataRate", &RF24::getDataRate)
    .def("setCRCLength", &RF24::setCRCLength)
    .def("getCRCLength", &RF24::getCRCLength)
    .def("disableCRC", &RF24::disableCRC)
    .def("printDetails", &RF24::printDetails)
    .def("powerDown", &RF24::powerDown)
    .def("powerUp", &RF24::powerUp)
    .def("writeFast", static_cast < bool (RF24::*)(const void*, uint8_t) > (&RF24::writeFast))
    .def("writeFast", static_cast < bool (RF24::*)(const void*, uint8_t, const bool) > (&RF24::writeFast))
    .def("writeBlocking", &RF24::writeBlocking)
    .def("txStandBy", static_cast < bool (RF24::*)() > (&RF24::txStandBy))
    .def("txStandBy", static_cast < bool (RF24::*)(uint32_t) > (&RF24::txStandBy))
    .def("startFastWrite", &RF24::startFastWrite)
    .def("startWrite", &RF24::startWrite)
    .def("reUseTX", &RF24::reUseTX)
    .def("writeAckPayload", &RF24::writeAckPayload)
    .def("isAckPayloadAvailable", &RF24::isAckPayloadAvailable)
    .def("whatHappened", &RF24::whatHappened)
    .def("testCarrier", &RF24::testCarrier)
    .def("testRPD", &RF24::testRPD)
    .def("isValid", &RF24::isValid)
    .def("maskIRQ", &RF24::maskIRQ)
    .def("setAddressWidth", &RF24::setAddressWidth)
    ;

  enum_<rf24_pa_dbm_e>("rf24_pa_dbm_e")
    .value("RF24_PA_MIN", RF24_PA_MIN)
    .value("RF24_PA_LOW", RF24_PA_LOW)
    .value("RF24_PA_HIGH", RF24_PA_HIGH)
    .value("RF24_PA_MAX", RF24_PA_MAX)
    .value("RF24_PA_ERROR", RF24_PA_ERROR)
    ;
  enum_<rf24_datarate_e>("rf24_datarate_e")
    .value("RF24_1MBPS", RF24_1MBPS)
    .value("RF24_2MBPS", RF24_2MBPS)
    .value("RF24_250KBPS", RF24_250KBPS)
    ;
  enum_<rf24_crclength_e>("rf24_crclength_e")
    .value("RF24_CRC_DISABLED", RF24_CRC_DISABLED)
    .value(" RF24_CRC_8",  RF24_CRC_8)
    .value(" RF24_CRC_16",  RF24_CRC_16)
    ;
    
}
