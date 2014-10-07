#include <boost/python.hpp>
#include "RF24.h"
using namespace boost::python;

BOOST_PYTHON_MODULE(RF24_lib)
{
  class_<RF24>("RF24", init<uint8_t,uint8_t, uint32_t>())
    .def("begin", &RF24::begin)
    .def("startListening", &RF24::startListening)
    .def("stopListening", &RF24::stopListening)
    .def("write", &RF24::write)
    .def("available", &RF24::available)
    .def("read", &RF24::read)
    .def("openWritingPipe", &RF24::openWritingPipe)
    .def("openReadingPipe", &RF24::openReadingPipe)
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
    .def("setAutoAck", &RF24::setAutoAck)
    .def("setPALevel", &RF24::setPALevel)
    .def("getPALevel", &RF24::getPALevel)
    .def("setDataRate", &RF24::setDataRate)
    .def("getDataRate", &RF24::getDataRate)
    .def("setCRCLength", &RF24::setCRCLength)
    .def("getCRCLength", &RF24::getCRCLength)
    .def("disableCRC", &RF24::disableCRC)
    ; // We didn't define old "compatibility" features
}
