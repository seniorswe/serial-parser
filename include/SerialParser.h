#pragma once

#include <cstdint>
#include <vector>
#include "Protocol.h"

namespace protocol {

class SerialParser {
public:
  SerialParser();

  void parseByte(uint8_t byte);
  bool hasMessage() const;

  SensorMessage getMessage();

private:
  void reset();

  ParseState state_;
  uint8_t currentDeviceId_;
  uint8_t currentPayloadLength_;
  std::vector<uint8_t> payloadBuffer_;
  uint8_t expectedChecksum_;

  std::vector<SensorMessage> processedMessages_;
};

} // namespace protocol