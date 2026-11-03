# Fluttering Butterfly Wings | 펄럭이는 나비 날개

[English](#english) · [한국어](#한국어)

## English

An Arduino servo animation for wearable butterfly wings. The sketch moves a servo smoothly between two angles with sine-in-out easing, creating a gentle and natural flapping motion.

### Features

- Smooth wing movement using sine-in-out easing
- Continuous motion between 20° and 135°
- 1.75-second travel time in each direction
- Short pause at each end of the movement
- Non-blocking control based on `millis()`
- Easy adjustment of angles, speed, pause time, and servo pulse range

### Hardware

- Arduino-compatible board
- Hobby servo motor
- Wearable butterfly wing mechanism
- Suitable power supply for the servo

### Wiring

| Servo wire | Connection |
| --- | --- |
| Signal | Pin 3 |
| VCC | Servo-compatible power supply |
| GND | Board GND and power-supply GND |

> Servos can draw more current than a microcontroller board can safely supply. Use an appropriate external power source when needed and connect all grounds together.

### Software requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- [`ServoEasing`](https://github.com/ArminJo/ServoEasing) library

Install `ServoEasing` from **Tools → Manage Libraries** in the Arduino IDE.

### Upload

1. Open `butterfly.ino` in the Arduino IDE.
2. Install the `ServoEasing` library.
3. Select your board and port.
4. Check that pin 3 is available as a servo signal output on your board.
5. Upload the sketch.

### Motion settings

| Setting | Value |
| --- | ---: |
| Start angle | 90° |
| Minimum angle | 20° |
| Maximum angle | 135° |
| One-way movement time | 1,750 ms |
| Pause at each end | 100 ms |
| Easing update interval | 20 ms |
| Servo pulse range | 1,000–2,000 µs |

Adjust the constants at the top of `butterfly.ino` to match the mechanical range of your wings and servo. Test new angle limits carefully to prevent the mechanism from binding.

### How it works

At startup, the servo moves from 90° to 20°. It then travels continuously between 20° and 135°. `EASE_SINE_IN_OUT` slows the servo near both ends of the movement, while the non-blocking update loop keeps the animation responsive.

---

## 한국어

착용형 나비 날개를 움직이는 Arduino 서보 애니메이션입니다. 사인 인아웃 이징으로 서보모터를 두 각도 사이에서 부드럽게 왕복시켜 자연스러운 날갯짓을 표현합니다.

### 주요 기능

- 사인 인아웃 이징을 적용한 부드러운 날개 움직임
- 20°에서 135°까지 반복 왕복
- 편도 1.75초의 날갯짓 속도
- 양 끝 지점에서 짧게 정지
- `millis()`를 이용한 논블로킹 제어
- 각도, 속도, 정지 시간, 서보 펄스 범위를 쉽게 조절

### 준비물

- Arduino 호환 보드
- 취미용 서보모터
- 착용형 나비 날개 구조물
- 서보모터에 맞는 전원

### 배선

| 서보 선 | 연결 위치 |
| --- | --- |
| 신호선 | 3번 핀 |
| 전원선 | 서보 규격에 맞는 전원 |
| 접지선 | 보드 GND와 외부 전원 GND |

> 서보모터는 마이크로컨트롤러 보드가 안정적으로 공급할 수 있는 전류보다 더 많은 전류를 사용할 수 있습니다. 필요하면 적절한 외부 전원을 사용하고, 보드와 외부 전원의 GND를 서로 연결하세요.

### 소프트웨어 요구 사항

- [Arduino IDE](https://www.arduino.cc/en/software)
- [`ServoEasing`](https://github.com/ArminJo/ServoEasing) 라이브러리

Arduino IDE의 **툴 → 라이브러리 관리**에서 `ServoEasing`을 검색해 설치하세요.

### 업로드 방법

1. Arduino IDE에서 `butterfly.ino`를 엽니다.
2. `ServoEasing` 라이브러리를 설치합니다.
3. 사용할 보드와 포트를 선택합니다.
4. 해당 보드에서 3번 핀을 서보 신호 출력으로 사용할 수 있는지 확인합니다.
5. 스케치를 업로드합니다.

### 움직임 설정값

| 설정 | 값 |
| --- | ---: |
| 시작 각도 | 90° |
| 최소 각도 | 20° |
| 최대 각도 | 135° |
| 편도 이동 시간 | 1,750 ms |
| 양 끝 정지 시간 | 100 ms |
| 이징 갱신 주기 | 20 ms |
| 서보 펄스 범위 | 1,000–2,000 µs |

날개 구조와 서보모터의 동작 범위에 맞게 `butterfly.ino` 상단의 상수를 조절할 수 있습니다. 각도 범위를 바꿀 때는 구조물이 걸리거나 서보에 무리가 가지 않도록 조금씩 테스트하세요.

### 동작 원리

전원을 켜면 서보가 90°에서 20°로 이동합니다. 이후 20°와 135° 사이를 계속 왕복합니다. `EASE_SINE_IN_OUT`이 양 끝에서 움직임을 감속하고, 논블로킹 업데이트 루프가 애니메이션을 안정적으로 유지합니다.
