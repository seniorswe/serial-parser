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

void SerialParser::parseByte(uint8_t byte) {
  switch (state_) {
  case ParseState::WAITING_FOR_START:
    if (byte == frame_start) {
      reset();
      state_ = ParseState::READING_DEVICE_ID;
    }
    break;
  case ParseState::READING_DEVICE_ID:
    currentDeviceId_ = byte;
    state_ = ParseState::READING_PAYLOAD_LENGTH;
    break;
  case ParseState::READING_PAYLOAD_LENGTH:
    currentPayloadLength_ = byte;
    if (currentPayloadLength_ == 0) {
      state_ = ParseState::CHECKSUM;
    } else {
      state_ = ParseState::READING_PAYLOAD;
    }
    break;
  case ParseState::CHECKSUM:
    break;
  case ParseState::PROCESSED:
    break;
  default:
    reset();
    break;
  }
} // namespace protocol