# Zero-Hour

## Inspiration
Almost every day we come across news about 2-wheeler accidents in the newspaper or media, and the rates have only kept increasing. What is even more disheartening is to hear that if help had reached the victim a little earlier then they could have been saved. To change this, we wanted to make something that is not only revolutionary but also very efficient. And this dream project doesn't end at this hackathon for we will keep working on it to turn it into a reality so that at least help reaches on time. 

## What it does
Zero Hour is an emergency alert / SoS device that can connect with emergency services and family members in the event of an accident or fall from a 2-wheeler. 
The solution is approached in the following steps:
- Detection of the accident by measuring a sudden jolt in the 2W. This is done by an accelerometer which will identify that sudden jolt in acceleration.
- A GPS module is attached to a WiFi μC (microcontroller) which will get the current coordinates, and the μC connects to the rider’s phone via the local hotspot. 
- On an accident, the μC reads the coordinates and is supposed to publish them to local IP which can be opened and visualised in a simple browser by typing the IP address of the μC, along with that a flag indicating the accident happened.
- An application on the phone reads the published data. Upon an accident, it sends SOS to the family members and to the nearby emergency services by calculating the nearest one stored in the phone. Along with that, it performs voice calls one a priority queue.

For the hackathon, we have worked on the hardware part and have enabled the message-sending capability using Twilio

## Features 
**Already Achieved:**
- Jolt detection on falling or other accidental occurrences  
- GPS feature: Acquiring location coordinates (lat and long)

**Future Goals:**
- Connected custom app with emergency message sending capabilities on the accidental situation 
- Sending of data to closest police stations, hospitals/medical units, and 5 emergency contacts saved by the user
- Pre-recorded automated call sending feature using the app to priority contacts
- Additional directory including all public emergency contacts as per their coordinates readily available - in the app for offline access
- Compact module like the controller design for ease of manufacturing and effective usage

## How we built it
The sensors detect the irregularity of motion caused due to the change in axis on the occurrence of an accident. Then this analog value is sent to the microcontroller for further analysis and to be acted upon. The sudden abnormality in data during the case of an accident acts as a trigger that flips the preset boolean variable that indicates an accidental condition. 
Then the microcontroller reads the location information from the GPS and simultaneously publishes the three variables to the app i.e. the flipped boolean value, latitudinal and the longitudinal coordinates of the rider’s location. 
Twilio part

## Challenges we ran into

## Accomplishments that we're proud of

## What we learned

## What's next for Zero Hour
