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
* \section seqfileprop Sequence File Properties
* Can be accessed via **Edit > Sequence File Properties**.
*
* \subsection Shared File Globals
* WIP
*
* \subsection File Format
* The dropdown allows the user to choose between
* saving the file in INI, XML, or binary format. For now, it doesn't matter.
* \image html SeqFileProperties.png "Sequence File Properties Menu" width=30%
* \image latex SeqFileProperties.png "Sequence File Properties Menu" width=30%
*
* \section usermng User Manager
* Can be accessed via **View > User Manager** or **Ctrl+U**. The user manager is used
* to add and remove users and user groups, as well as edit information such as 
* passwords and privileges. If you wish, add a new user profile for yourself, making sure
* to grant yourself admin privileges.
* \image html UserManager.png "User Manager" width=50%
* \image latex UserManager.png "User Manager" width=50%
*
* \section stationopts Station Options
* Can be accessed via **Configure > Station Options**.
*
* \subsection exe Execution
* This panel contains important settings related to test sequence execution. Enable
* Breakpoints should be enabled, as well as Allow Break While in Code Modules. This ensures
* that test sequences can be properly debugged, especially when stepping into code
* modules. Additionally, Enable Tracing should be turned on.
* \image html Execution.png "Station Options Execution Panel" width=30%
* \image latex Execution.png "Station Options Execution Panel" width=30%
*
* \subsection model Model
* This panel contains settings related to the station model. TestStand supports three 
* station models: 
* -# **Parallel**: Runs the test sequence on multiple UUTs independently and concurrently, testing a new UUT
* whenever a test socket becomes available.
* -# **Batch**: Runs the test sequence on multiple UUTs similar to parallel, but synchronizes
* execution such that tests start at the same point and wait until they reach specific
* synchronization points
* -# **Sequential**: Runs the sequence on one UUT at a time.
*
* At Arxtron, we typically use the Parallel station model, but it's good to be familiar with all three models.
* \image html Model.png "Station Options Model Panel" width=32%
* \image latex Model.png "Station Options Model Panel" width=32%
*
* \section searchdirs Search Directories
* Can be accessed via **Configure > Search Directories**. Used to configure TestStand's
* search directories. Ensure that **C:\Arxtron\Libraries** is added, with the "Subdirs" option
* selected; this allows TestStand to find and reference Arxtron library .dlls.
* \image html SearchDirs.png "Search Directories Menu" width=50%
* \image latex SearchDirs.png "Search Directories Menu" width=50%
*
* \section modelopts Model Options
* Can be accessed via **Configure > Model Options**. Primarily used to select the number
* of "Test Sockets", or the max number of UUTs that can be tested simultaneously.
* \image html ModelOptions.png "Model Options Menu" width=30%
* \image latex ModelOptions.png "Model Options Menu" width=30%
* 
*******************************************************************************/

/***************************************************************************//*!
* \page developing Developing a Test Sequence
* * \subpage vars
* * \subpage steps
* * \subpage types
* * \subpage flow
*******************************************************************************/

/***************************************************************************//*!
* \page running Running a Test Sequence
*
* \section execute Program Execution
*
* \subsection modes Step Run Modes
* Right-clicking on a test step and navigating to **Run Mode** reveals the available step run modes.
* These step modes often prove useful while debugging.
* - **Force to Pass**: the test step always passes regardless of the actual test result.
* - **Force to Fail**: the test step always fails regardless of the actual test result.
* - **Skip**: the test step is skipped during sequence execution (used to "comment out" steps).
* - **Normal**: the test step runs normally.
*
* \subsection running Running the Sequence
* There are a few ways to run a TestStand sequence. To see these options,
* hover over **Execute**.
* - **Test UUTs**: Runs the sequence utilizing the station model.
* - **Single Pass**: The same as **Test UUTs**, but only tests one UUT.
* - **Run MainSequence**: Runs the MainSequence directly without using the station model (useful for debugging).
*
* \subsection running2 Running Selected Steps
* To run a subset of steps from a sequence, select the desired steps within the Steps Pane
* and right click, selecting **Run Selected Steps**. This can also be done from **Execute > Run Selected Steps**.
*
* \section debug Debugging
* Debugging a TestStand sequence can be approached similar to conventional code debugging.
*
* \subsection analyze Sequence Analyzer
* TestStand's sequence analyzer is a tool that will attempt to point out potential
* issues in a sequence. It can be run via **Debug > Sequence Analyzer > Analyze "SequenceFileName.seq"**.
* Additionally, it can be automatically set to run before any execution, via **Debug > Sequence Analyzer > Toggle Analyze File Before Executing**.
*
* Sequence analysis results will populate in the Analysis Results Pane, which is in the same
* location as the Step Settings Pane.
*
* \subsection breakpoints Breakpoints & Watch Expressions
* Breakpoints can be set by navigating to **Debug > Breakpoints/Watches**, and adding
* a breakpoint via the resulting menu. Note that watch expressions can also be set from 
* within the menu.
*
* Alternatively, clicking within the white space directly to the left of a test step
* will enable a breakpoint.
* \image html Breakpoint.png width=30%
* \image latex Breakpoint.png width=30%
*
* \subsection stepcommands Step Commands
* While executing a sequence with breakpoints, standard debugging step commands
* can be used. They can be found under **Debug**; here are some of the most useful ones:
* - **Resume**: Resumes execution until the next breakpoint is reached (F5).
* - **Step Over**: Steps over the current test step without resuming execution (F8).
* - **Step Into**: Steps into the current test step (F10). Especially useful for
* stepping into the source code of a code module.
*
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
* <td>24/3/2026
* <td>Initial Release
* </table>
*******************************************************************************/
