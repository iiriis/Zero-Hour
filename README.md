# Zero-Hour

## Inspiration
Almost every day we come across news about 2-wheeler accidents in the newspaper or media, and the rates have only kept increasing. What is even more disheartening is to hear that if help had reached the victim a little earlier then they could have been saved. To change this, we wanted to make something that is not only revolutionary but also very efficient. And this dream project doesn't end at this hackathon for we will keep working on it to turn it into a reality so that at least help reaches on time. 

## What it does
Zero Hour is an emergency alert / SoS device that can connect with emergency services and family members in the event of an accident or fall from a 2-wheeler. The solution is approached in the following steps:
- Detection of the accident by measuring a sudden jolt in the 2Wheeler, this sudden jolt can reach acceleration more than (±16g) which is pretty huge. This is measured by an accelerometer which will identify that sudden jolt in acceleration.
- A GPS module is attached to a WiFi μC (microcontroller) which will get the current coordinates, and the μC connects to the rider’s phone via the mobile hotspot.
- On an accident, the μC reads the coordinates acquired by the GPS and connects to the TWILIO service for messaging.
- The firmware then calls the TWILIO API to contact the Emergency Numbers on a queue basis, thus alerting for help and emergency.
- Along with that, in the Future we will be implementing services so that it performs voice calls one a priority queue.
For the hackathon, we have worked on the hardware part and have enabled the message-sending capability using Twilio.

## Features 
**Already Achieved:**
- Jolt detection on falling or other accidental occurrences
- GPS feature: Acquiring location coordinates (lat and long)
- Connected to the TWILIO service using ESP32 for sending messages
- Made the final prototype working

**Future Goals:**
- Connected custom app with emergency message sending capabilities on the accidental situation
- Sending of data to closest police stations, hospitals/medical units, and 5 emergency contacts saved by the user
- Pre-recorded automated call sending feature using the app to priority contacts
- Additional directory including all public emergency contacts as per their coordinates readily available - in the app for offline access
- Compact module like the controller design for ease of manufacturing and effective usage

## How we built it
The accelerometer detect the irregularity of motion caused due to the change in axis on the occurrence of an accident. Then this analog value is sent to the microcontroller for further analysis and to be acted upon. The sudden abnormality in data during the case of an accident acts as a trigger that flips the preset boolean variable that indicates an accidental condition. Then the microcontroller reads the location information from the GPS and connects to TWILIO for sending the latitudinal and the longitudinal coordinates of the rider’s location to the emergency contacts.

## Challenges we ran into
The time crunch is a great challenge for all teams we guess and we are no exception to that. Making the hardware work with limited components was the biggest challenge of all, **probably the hackiest hack one will see at this hackathon ;)** 

## Accomplishments that we're proud of
This is the first time we tried to use and incorporate Twilio and once it worked as it is supposed, that was a moment of great relief and achievement. And the GPS was not warm, we really had a hard time getting the GPS run. And while using the default hardware I2C of the ESP32, we were getting some unknown errors and it was getting reset by itself. So debugging that and finally getting a solution by reading the whole .cpp file of the I2C library and changing the address in them was a major breakthrough. Apart from that, twenty-four hours went by really fast and honestly, we are just glad to have reached our goals for the hack that we wanted to establish in this hackathon.

## What we learned
- Since we had never worked with Twilio before, it was definitely something we learned and we cant wait to explore the other services.
- Parsing NMEA data for location by ourselves was a great learning too.
- Learned how to use the complementary I2C bus in the ESP32, using the direct TwoWire() methods.

## What's next for Zero Hour
The next step for us would be turning Zero Hour into a reality, by making it a full-fledged usable product. We will be working on building the controller, and hopefully, increase our team to create the app as discussed in the Features Future Goals. Even though it might be a long journey till productisation, but today we have already planted the seed.
