# GP-Synth
 
 This is my first VST Synth developed in C++ 
 (with [Juce](https://juce.com/)) in order to 
 learn more about Digital Sound Processing.  
 
 /!\ Work is still in progress!
 
 
 ### Frameworks and Libraries
 
 * [Juce](https://juce.com/) : a framework for UI and Sound 
 apps/plugins. You will need to install the framework, including 
 Projucer, a software which builds the project according to Juce 
 parameters
 * [Maximilian](https://github.com/micknoise/Maximilian): an audio 
 synthesis and signal processing library written in C++ (the files are included in this repository)
 
 ### Using it
 
To use the code, you will need to launch `GPSynth.jucer` with Projucer
and to build the project with it.

You can use the plugin in any DAW, as it is compiled as a VST3 plugin.
 

 ### GUI Files Hierarchiy
 
The GUI Files are organized as follows:
 
 ```
 PluginEditor  
 |  KeyboardComponent
 |
 └──MainComponent
     └──LeftComponent
         └──LeftComponent
         │   └──OscillatorGroupComponent
         │   │   └──OscillatorComponent
         │   └──FilterGroupComponent
         │       └──FilterComponent
         └──MiddleComponent
         │   └──EnvelopeComponent
         │   └──LfoComponent
         └──RightComponent
 
 ```
 

 ## Ressources
 
 Here are links to tutorials and guides that I used in order to 
 learn Juce and be able to develop this plugin: 
 
 * [Juce Official Tutorials](https://juce.com/learn/tutorials)
 * [The Audio Programmer Youtube Channel](https://www.youtube.com/theaudioprogrammer)
 
 Thanks to their authors who made a really nice work!
 

