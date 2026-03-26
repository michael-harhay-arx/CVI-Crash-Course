/***************************************************************************//*!
* \mainpage Start Here
*
* \section intro Introduction
*
* \subsection howto About this Guide
* Welcome to the Arxtron CVI crash course. The aim of this guide is to
* succinctly summarize the key functionalities of CVI as used at Arxtron;
* however, it is not intended to be exhaustive. For further support, you can ask
* a colleague, or consult the official documentation.
*
* If this is your first time reading the guide, it is recommended that you
* follow it sequentially and follow along in CVI when applicable.
*
* \subsection whyuse Why Use CVI?
* LabWindows/CVI is an IDE specifically designed for test, measurement, and control applications.
* While fairly similar to any other IDE with C support, it features a handy GUI editor that can be 
* used to quickly develop a frontend for any test setup.
*
* \section start Getting Started
* 
* \subsection open Open CVI
* -# Press the Windows key and search for "CVI".
* -# Open "NI LabWindows CVI 2019".
* -# You will be met with the CVI Welcome menu. From here, you can access recent projects, 
* start a new project from a template (or from scratch), and open help documents and example projects.
* Feel free to follow along in CVI by selecting any of the available options.
* \image html Welcome.png "CVI Welcome Menu" width=40%
* \image latex Welcome.png "CVI Welcome Menu" width=40%
*
* \subsection familiarize Familiarize Yourself
* Take a few moments to familiarize yourself with the general layout of the program.
* \image html CVIDefault.png "Default CVI Layout" width=70%
* \image latex CVIDefault.png "Default CVI Layout" width=70%
The interface is divided into the following panes:
* -# **Project Tree**: Used to browse the current project's structure.
* -# **Library Tree**: Used to browse libraries.
* -# **Window Confinement Region**: The primary region for editing code.
* -# **Toolbar**: displays various icons which can be used to perform various actions.
*
* If any of these panes do not appear by default, they can be toggled from within the **View** menu.
* 
* Additionally, CVI does not show line numbers by default. It is recommended that you 
* select **View > Line Numbers** to toggle this setting.
*
*******************************************************************************/

/***************************************************************************//*!
* \page terms Terminology
*******************************************************************************/

/***************************************************************************//*!
* \page config Configuration & Options
*
* CVI contains a number of menus containing configuration settings and options.
* This section of the guide will briefly list the most important settings and
* their recommended states.
*
* \section buildsettings Build Settings
*
* \subsection buildconfig Build Configurations
* Can be accessed via **Build > Configuration**. The resulting dropdown lists 
* the available build configurations; more can be added by selecting
* **Manage Configurations**. The main configurations are:
* - **Debug**: This configuration allows for debugging.
* - **Release**: This configuration does not allow debugging, and is the most optimized for release.
* - **Debug64**: 64-bit version of **Debug**.
* - **Release64**: 64-bit version of **Release**.
* \image html BuildConfig.png "Build Configuration Menu" width=30%
* \image latex BuildConfig.png "Build Configuration Menu" width=30%
*
* \subsection buildtargettype Build Target Type
* Can be accessed via **Build > Target Type**. The resulting dropdown lists 
* the available build target types:
* - **Executable**: a standalone application that can be executed.
* - **Dynamic Link Library (DLL)**: a library file that is linked at run time. DLLs
* are less portable and are not self-contained, but offer easier maintenance (simply replace 
* the desired DLL without needing to recompile everything) and take up less space.
* - **Static Library**: a library file that is linked at compile time. Static libraries 
* have the advantage of being self-contained, however they are much larger. Additionally,
* updating a static library requires recompiling.
* \image html TargetType.png "Build Target Type Menu" width=30%
* \image latex TargetType.png "Build Target Type Menu" width=30%
*
* \subsection buildtarget Build Target Settings
* Can be accessed via **Build > Target Settings**. Target settings are used to
* configure the various target types. These settings typically aren't touched,
* but are good to know about.
* \image html Target.png "Build Target Settings Menu" width=40%
* \image latex Target.png "Build Target Settings Menu" width=40%
* 
* \section environment Environment
* 
* \subsection include IncludePaths
* Can be accessed via **Options > Environment > Include Paths**. This menu determines
* CVI's search directories. Ensure that "C:\Arxtron\Libraries" is included.
* \image html Environment.png "Include Paths Menu" width=42%
* \image latex Environment.png "Include Paths Menu" width=42%
*
* \section editor Editor Preferences
* 
* Can be accessed via **Options > Editor Preferences**. Typically, these settings
* should not be changed, but are good to know about.
* \image html EditorPrefs.png "Editor Preferences Menu" width=25%
* \image latex EditorPrefs.png "Editor Preferences Menu" width=25%
*
*******************************************************************************/

/***************************************************************************//*!
* \page running Running a CVI Project
*
* \section runningsection Running a CVI Project
* \subsection building Building a Project
* To compile a CVI project, follow these steps:
* -# Ensure that the correct target type is selected.
* -# If just the current file needs to be compiled, press **Ctrl+K** to do so.
* Otherwise, press **Ctrl+M** to build the entire project.
* -# Warnings, errors, and other build-related messages will appear in the
* **Build Output Pane**
* \image html BuildOutput.png "Build Output Pane" width=80%
* \image latex BuildOutput.png "Build Output Pane" width=80%
*
* \subsection procattach Attach to Process 
* When calling C code from a TestStand sequence or some other executable,
* you can open the corresponding source project in CVI and select **Run > Attach to Process**
* to attach to the process. This allows the current process to be debugged using
* all of CVI's debug features.
*
* Similarly, **Run > Detach from Process** can be used to detach an attached CVI
* instance. This is often useful when stepping into CVI code from TestStand, as
* terminating the process from CVI without detaching will halt the entire 
* TestStand sequence.
*
* \section debug Debugging
*
* \subsection breakpoints Breakpoints & Watch Expressions
* Breakpoints can be set by navigating to **Run > Breakpoints** (**Shift+F7**),
* and adding a breakpoint via the resulting menu. 
*
* Alternatively, clicking within the grey space directly to the left of a line
* number will enable a breakpoint.
* \image html Breakpoint.png width=20%
* \image latex Breakpoint.png width=20%
*
* Watch expressions can be set by selecting a line of code, then selecting
* **Run > Add Watch Expression** or by pressing **Shift+F9**.
*
* \subsection stepcommands Step Commands
* While executing a sequence with breakpoints, standard debugging step commands
* can be used. They can be found under **Run**; here are some of the most useful ones:
* - **Resume**: Resumes execution until the next breakpoint is reached (F5).
* - **Set Next Statement**: Sets program to run from selected line (Ctrl+Shift+F7 / right click menu).
* - **Step Over**: Steps over the current line without resuming execution (F8).
* - **Step Into**: Steps into the current line of code (F10).
*
* \subsection debugwindows Debug Windows
* CVI features a number of windows that are useful for debugging (found under **Window**). Here are a few useful ones to explore:
* - **Memory**: displays the memory of the current program.
* - **Resource Tracking**: displays both allocated and deallocated from the current program.
* - **Variables and Call Stack**: displays all program variables and their values, as well as a standard call stack.
* - **Watch**: displays all user-defined watch expressions.
* - **Threads**: displays threads in the current program.
*
*******************************************************************************/

/***************************************************************************//*!
* \page gui GUI Development
*
* \section guistart Getting Started
* CVI is useful because of its built-in GUI editor. The easiest way to begin
* developing a GUI is to copy the Arxtron template.
*
* TODO: Talk about how to use Arxtron GUI
*
* \section guidev Working with the GUI Editor
* 
* -# **GUI Editor Pane**: The region in which GUI editing takes place.
* -# **Objects Pane**: This pane contains a list of present GUI objects.
* -# **Object Properties Pane**: When a GUI object is selected, its properties
* appear in this pane.
* -# **Help Pane**: This pane displays helpful messages about the current selection.
*
* \image html GUIDefault.png "Default CVI GUI Editor Layout" width=70%
* \image latex GUIDefault.png "Default CVI GUI Editor Layout" width=70%
*
* To create a GUI element, right click anywhere and make a selection.
*******************************************************************************/

/***************************************************************************//*!
* \page tips Tips & Tricks
*******************************************************************************/

/***************************************************************************//*!
* \page changelog Change Log
* <table>
* <tr><th>Version<th>Author<th>Date<th>Changes
* <tr><td>1.0.0
* <td>Michael Harhay
* <td>25/3/2026
* <td>Initial Release
* </table>
*******************************************************************************/
