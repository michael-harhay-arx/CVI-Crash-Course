/***************************************************************************//*!
* \page vars Variables
* Variables in TestStand work similarly to variables in most programming languages. The following section will detail how they work.
* 
* \section vartypes Variable Types
* - **Number**: encompasses all numeric types.
* - **String**: note that there is no "char" variable type, only string.
* - **Boolean**
* - **Object Reference**: references an object (similar to a pointer).
* - **Container**: a structure that can hold members of various data types (similar to a C struct).
* - **Type**: a user-defined datatype.
* - **Array**
*
* \section varscope Variable Scopes
From smallest to largest:
* - **Step**: Only exists within the current test step.
* - **Local**: Only exists within the current sequence.
* - **Parameters**: Must be passed into the current sequence by the caller sequence.
* - **FileGlobals**: Global variables that exist everywhere within a sequence file.
* - **StationGlobals**: Variables shared across the "station" (all sequence files have access).
* - **ThisContext**: The current sequence "context".
* - **RunState**: A broad grouping encompassing the TestStand engine and Context, as well as other items.
*
* Note: **ThisContext** and **RunState** are typically only used when working with 
* the API. However, feel free to familiarize yourself with them.
*
* \image html Scopes.png "TestStand Variable Scopes" width=25%
* \image latex Scopes.png "TestStand Variable Scopes" width=25%
*
* \section workwithvars Working with Variables
* 
* \subsection Creating Variables
* To create a variable, right click under the desired scope in the Variables Pane. Then select the desired
* type from the resulting dropdown.
* \image html InsertVar.png width=30%
* \image latex InsertVar.png width=30%
*
* There is another useful way to create variables: type the desired variable name into any expression box,
* right click the variable name, and select **Create "variable name" > Desired variable type**.
* \image html CreateVar.png width=35%
* \image latex CreateVar.png width=35%
*
* \subsection Passing Variables into Code Modules
* It is very important that all variables being passed between TestStand and 
* external C code have the appropriate type. To check how variables are being passed 
* into a step, select the step in the Steps Pane, which will open the Step Settings Pane.
* Then, select a parameter to view its properties on the right side of the pane.
* \image html VarPassType.png width=90%
* \image latex VarPassType.png width=90%
* In this case, it would be important to ensure that DIO_GetDeviceIndex() from DIO_LIB.dll
* is supposed to take a pointer to a **signed 32-bit integer** for the parameter DeviceIndex.
* 
*******************************************************************************/
/***************************************************************************//*!
* \page steps Test Steps
* 
* \section tstypes Test Step Types
* TestStand contains many step types, which can be used to build test sequences.
* Here are a few of the most commonly used step types:
*
* \subsection action Action
* Calls a code module that does not perform a test. For example, an action step might initialize an instrument to prepare it for testing.
* \image html action_steptype.png width=6%
* \image latex action_steptype.png width=6%
*
* \subsection pf Pass/Fail
* Calls a code module that makes its own pass/fail determination. Note that this module does not appear by default in the Insertion Palette;
* to insert a pass/fail step, right click the Steps Pane and select **Insert Step > Tests > Pass/Fail Test**.
* Within this menu are a few other types of code module tests.
* \image html pf_steptype.png
* \image latex pf_steptype.png
*
* \subsection sc Sequence Call
* Calls another sequence in the current sequence file or in another sequence file.
* \image html seqcall_steptype.png width=10%
* \image latex seqcall_steptype.png width=10%
*
* \subsection statement Statement
* Executes a TestStand expression. For example, a statement step can be used to increment the value of a local variable.
* Note that statement steps do not return a pass/fail status by default; step status can
* be set in the Step Settings Pane under **Properties > Expressions > Status Expression**.
* \image html statement_steptype.png width=8%
* \image latex statement_steptype.png width=8%
*
* \subsection flowctrl Flow Control
* Flow control step types implement standard programming branching statements.
* \image html flowctrl_steptype.png width=10%
* \image latex flowctrl_steptype.png width=10%
*
* \subsection db Database
* Database step types can be used to easily communicate with databases, which is often useful for logging functionality.
* \image html db_steptype.png width=14%
* \image latex db_steptype.png width=14%
*
* \section workwithsteps Working with Test Steps
*
* \subsection createteststep Creating a Test Step
* To create a test step, simply drag and drop from the Insertion Palette into the Steps Pane.
* Alternatively, right click within the Steps Pane and select **Insert Step > Desired step type**.
*
* \subsection editteststep Editing a Test Step
* To edit a step, select it in the Steps Pane and navigate to the Step Settings Pane if it is not already open.
* Within the Step Settings Pane, there are typically (but not always) two tabs: **Properties**
* and **Step-Specific Settings**. Take some time to try experimenting with these tabs within multiple step types.
*
* \subsubsection stepprops Step Properties
* The **Properties** tab is a standard set of properties that appear in all TestStand step types.
* \image html stepproperties.png "Step Properties Tab" width=85%
* \image latex stepproperties.png "Step Properties Tab" width=85%
*
* There are a few key properties to note, all of which are used often at Arxtron (see \ref stepflow for more details):
* - **Post Actions**: Determines how the sequence should behave depending on the result of the current test step.
* - **Expressions**: Pre- and Post-Expressions are TestStand expressions that will run before and after the
* execution of the current step. The Status Expression determines the output status of the test (pass/fail)
* - **Preconditions**: A TestStand expression that determines whether or not the current step is run in the sequence, via a logical condition.
*
* \subsubsection stepsettings Step-Specific Settings
* **Step-Specific Settings** vary between test step types.
*
* For example, an Action test step's settings primarily concerns the passing of
* parameters between TestStand and the code module.
* \image html stepsettings.png "Step-Specific Settings Tab for an Action Test Step" width=85%
* \image latex stepsettings.png "Step-Specific Settings Tab for an Action Test Step" width=85%
*
*******************************************************************************/
/***************************************************************************//*!
* \page types Types 
* 
* TestStand supports the creation of custom variable and step types. This functionality can be accessed from the Types Pane.
*
* \section typespane The Types Pane
* The Types Pane can be opened via **View > Types** or by pressing **Ctrl+T**.
* \image html Types.png "Types Pane" width=60%
* \image latex Types.png "Types Pane" width=60%
*
* \section workwithtypes Working with Types
* 
* \subsection creatingtype Creating a Type
* To create a type, simply right click under the desired type list and follow
* the resulting pop-up menu.
*
* \subsection typeprops Data Type Properties
* When creating a custom data type, it is important that you correctly configure 
* its properties. To do so, right click the data type and select **Properties**.
*
* The most important property to be aware of is C Struct Passing, as it allows 
* variables of this data type to be passed into C code modules as C structs. To set
* up this functionality, follow these steps:
* -# Click the checkbox titled "Allow Objects of this Type to be Passed as Structs"
* -# For each field in the data type, ensure that the type matches the type defined by the corresponding code module parameter.
* \image html TypeProperties.png "Data Type Properties Window" width=30%
* \image latex TypeProperties.png "Data Type Properties Window" width=30%
*
*******************************************************************************/
/***************************************************************************//*!
* \page flow TestStand Flows
* 
* \section seqflow Sequence Flow
* TestStand follows a standard order of sequences within a sequence file, outlined by the following flowchart.
* If the following sequences do not appear in TestStand, navigate to **Edit > Sequence File Callbacks**.
* From that menu, you can add default TestStand callback sequences.
* -# **ProcessSetup**: Used for program setup (e.g. starting threads, initializing libraries).
* -# **PreBatch**: If batch model is active, runs before each batch.
* -# **PreUUT**: Runs before each UUT.
* -# **MainSequence**: Primary test sequence to be run.
* -# **PostUUT**: Runs after each UUT.
* -# **PostBatch**: If batch model is active, runs after each batch.
* -# **ProcessCleanup**: Used for program cleanup.
*
* \image html SequencerFlow.png "TestStand Sequence Flow" width=40%
* \image latex SequencerFlow.png "TestStand Sequence Flow" width=40%
*
* \section stepflow Test Step Flow
* TestStand also follows a standard procedure within each test step, as outlined below.
* -# **Preconditions**: See \ref stepprops.
* -# **Loop Initialization Expression**: Used to initialize loop variables (e.g. int i = 0).
* -# **Pre-Expression**: See \ref stepprops.
* -# **Module Action**: Main module action.
* -# **Post-Expression**: See \ref stepprops.
* -# **Status Expression**: Determines pass/fail status of step.
* -# **Loop Increment Expression**: Increments loop variables (e.g. i++).
* -# **Loop While Expression**: Checks loop condition (e.g. i < 10).
* -# **Loop Status Expression**: Determines pass/fail status of loop.
* -# **Post Actions**: See \ref stepprops.
*
* \image html StepFlow.png "TestStand Test Step Flow" width=30%
* \image latex StepFlow.png "TestStand Test Step Flow" width=30%
*
*******************************************************************************/