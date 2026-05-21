#include "SerialParser.h"

namespace protocol {

SerialParser::SerialParser() { state_ = ParseState::WAITING_FOR_START; }

void SerialParser::reset() {
  state_ = ParseState::WAITING_FOR_START;
  payloadBuffer_.clear();
  currentDeviceId_ = 0;
  currentPayloadLength_ = 0;
  expectedChecksum_ = 0;
}

} // namespace protocol