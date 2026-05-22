#pragma once

#include <cstdint>
#include <vector>

namespace protocol {

static constexpr uint8_t frame_start = 0xAA;
static constexpr uint8_t frame_end = 0x55;

enum class ParseState {
  WAITING_FOR_START,
  READING_DEVICE_ID,
  READING_PAYLOAD_LENGTH,
  READING_PAYLOAD,
  CHECKSUM,
  PROCESSED
};

struct SensorMessage {
  uint8_t deviceId;
  std::vector<uint8_t> payload;
};

} // namespace protocol