# EdgeLibrary
EdgeLibrary is a static library of classes designed to make CS:GO cheats more easily.
It is based on inVincibleLib made by WasserEsser (UnknownCheats), but I've added some stuff and edited a lot of it.

## What you can find in this library

- **MemoryManager**

MemoryManager static class handle the memory indeed. It declares and implement useful functions based on Windows WPM and RPM. There are also functions for Pattern Scanning to find dynamic offsets in memory on-fly.

- **OffsetManager**

Offsets class is an useful static container for several offsets which comes handy when making CS:GO cheats. It implements a function to set the offsets through an INI file, or by Pattern Scanning the memory using MemoryManager.

- **ResourceManager**

Resources class is an useful static container for resources that you always need to make a cheat. It's a container for modules like client.dll or engine.dll.

- **LogManager**

Log static class implements a very neat system to make logs in txt files in a matter of seconds. It comes useful while debugging.

- **ClientManager**

Client static class allows you to read inside the client.dll module, in order to acquire useful informations about the client and set them as well very easily.

- **LibraryManager**

LibraryManager static class implements, first of all, the main setup function for the cheat. However, it implements also a lot of useful functions that help you when you are coding (for example a function to convert from char* to LPCWSTR, or a function to calculate the angle between a source and a destination).

- **LocalPlayerManager**

LocalPlayer static class allows you to get and set a lot of data into the LocalPlayer of CS:GO. You can also use it as a base to get only the player base address and then do stuff externally, but it does actually implement a lot of useful stuff.

- **EntityManager**

EntityManager static class is a lot similar to LocalPlayer, but it implements functions to get and set data into a certain Entity (tagged by an Index) in CS:GO.

- **CHEntityManager**

CHEntityManager static class is identical to the EntityManager, the only thing different is that it implements functions to get and set data into the Entity actually in the middle of the LocalPlayer's crosshair. This comes a lot handy when making stuff like triggerbot or slowaim.

- **GlowObjectPlayer**

GlowObjectPlayer is a struct, implemented in the EdgeLibrary namespace, which describe the Glow Instance. It is used to make external GlowESP, and it's based on the internal already-defined struct. All you have to do is to fill the parameters (or edit them), and write the whole struct into the GlowObject offset.

- **Vector2** and **Vector3**

Bot of them are classes which only defines an X and an Y in case of Vector2; an X, an Y and a Z in case of Vector3. These two kind of vectors are a lot used in CS:GO.
