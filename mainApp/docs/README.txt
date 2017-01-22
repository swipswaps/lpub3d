LPub3D 2.0.19.877.2 
 
Features and enhancements 
------------ 
Fix: Callout not displayed and part count incorrect when loading a model using multiple, separate ldr-format files (r877) 
 * These behaviours were introduced in LPub3D 2.0.0. The immediate work around is to merge the individual ldr files into a single MPD-format file. However, these behaviours are now corrected.  
 
LPub3D 2.0.18.876.2 
 
Features and enhancements 
------------ 
Fix: Instance count placement when page number not displayed (r874) 
 * Instance count is placed relative to page number by default. When page number is not displayed, LPub3D will re-assign the instance count to any or the four page attributes, url, email, copyright, and author (default) displayed at the left bottom area of the page. If no page attributes are displayed, the instance count is assigned to the bottom left inside corner of the page. 
Fix: Fade part not displayed in assembly image (r872) 
 * The faded part is not rendered or displayed in the CSI step image. The non-faded part occurrence is rendered successfully and the faded part is displayed in the viewer.The problem persists after regenerating fade parts and clearing the cache. In some scenarios, particularly when LPub3D is launched with fade=Off and then fade is set to fade=ON using the Preferences menu after a model file is loaded, it is possible that the fade directory is not communicated to the renderer so no fade part image is rendered. This behaviour has been corrected. 
 With the updated behaviour, the fade search directories are updated on any change to the Fade Step check-box in the Preferences General tab. If the fade step is set to ON, fade directory with part file content will be added to the search directory. When fade step is set to OFF, the fade directory will be removed. 
Fix: True page background transparency (r871) 
 * When the page background is set the true transparent, it is not possible to display the background context menu so many page functions will not be accessible. To accommodate true transparency and enable the available page editing functions, when a page background is set to "none(transparent)" by the user, the page is set to white with alpha=1 during page editing but switched to true transparent for exporting/printing. This way, the user will have the ability to manipulate the page components while editing the document. 
Fix: Previewing the current page (single page) produces a blank page (r870) 
 * This behaviour has been corrected. 
Fix: Page size precision to 4 decimal places (r869) 
 *  When using some page sizes (e.g. A4), there was a thin white band at the right/bottom edge of the generated PDF pages when the background is set to colour or image. This issue resulted from using incorrect page sizes. The correct page size in inches sometimes require 4 digits of precision but were rounded to only 1 digit. All page sizes have been set to 4 digits of precision. 
Fix: Border meta automatically updated to LPub3D format (r868) 
 * LPub3D will automatically detect and update a LPub border meta to the LPub3D format which adds a line type attribute to the meta command. The previous behaviour would display an error format message prompting the user to correct the meta. The default line type set during automatic update is 1=solid. 
 Line types are  0=none,1=solid,2=dash,3=dot,4=dashDot,5=dashDotDot. An LPub meta line like this: 
 0 !LPUB PLI BORDER GLOBAL ROUND Black 0 15 MARGINS 0.472439 0.07 will be automatically updated to this: 
 0 !LPUB PLI BORDER GLOBAL ROUND 1 Black 0 15 MARGINS 0.472439 0.07 
Fix: Find button in LDraw editor (r867) 
 * Find button added to LDraw editor. The find dialogue will open with the word currently under the cursor. Therefore, an efficient use pattern is to place the cursor above the word you wish to search and click the search button. 
Fix: Display message for mixed page size and orientation (r866) 
 * When previewing a pdf export, the user has to option to present or suppress the message indicating there are different orientations and/or sizes in the preview. The Qt print preview does not play well with mixed pages sizes. This message informs the user of this fact. Additional Cleanup. 
Fix: Misplaced submodel occurrence (r865) 
 * When a submodel ends with a single step and the next to the last step is a multi-step, the submodel occurrence number (if used more than 1x in the parent model) is placed both at the multi-step and the last step in the child model. Under this scenario, the corrected behaviour places the occurrence number only at the last step. 
 
LPub3D 2.0.17.863.2 
 
Features and enhancements 
------------ 
Fix: Inconsistent page size/orientation transition (r862) 
 * Size and orientation transition is inconsistent between the editor and export for mixed orientation output. Editor and export page orientation corrected to behave the same. Here are some notes to describe how to use the different meta commands: 
 - Use the page context menu to set size and/or orientation to ensure proper meta command syntax. 
 - GLOBAL (e.g 0 !LPUB PAGE ORIENTATION GLOBAL PORTRAIT) meta keyword should only be used at the header of the top level model file - if you are manually adding meta commands in the LDraw editor. 
 - LOCAL (e.g 0 !LPUB PAGE ORIENTATION GLOBAL PORTRAIT) meta keyword will scope the meta command to only the current step - if you are manually adding meta commands in the LDraw editor.. 
 - When the LOCAL keyword is absent (e.g. 0 !LPUB PAGE ORIENTATION PORTRAIT), the meta command takes on the same behaviour as if the GLOBAL keyword is used - i.e. the meta command takes on a global scope from the point where it is used - unless it is superseded by a new meta command. 
 - When manually setting size and/or orientation on a child submodel (i.e. using the LDraw editor), place your command in the child submodel instead of placing it in the parent model. For MULTI_STEP(s), place the size orientation at the bottom of the MULTI_STEP - just before 0 !LPUB MULTI_STEP END. 
Fix: Empty output after export to pdf or images (r861) 
 * The page size was not captured during export (pdf or images) unless an explicit definition of the page size meta command is present in the model file (e.g. 0 !LPUB PAGE SIZE GLOBAL 8.5000 11.0000 Letter). This behaviour is now corrected. 
Fix: When page number is not displayed, the submodel instance count is also not displayed (r860) 
 * Instance count is by default placed relative to page number so, by default, if page number is not displayed then instance count is also not displayed. This behaviour is now changed to automatically set the instance count relative to the page if the page number is not displayed. As a result, the instance count will display regardless of the display status of the page number. 
 
LPub3D 2.0.16.858.2 
 
Features and enhancements 
------------ 
Fix: Prompt to download LDraw archive when archive not provided (r856) 
 * When a portable distribution of LPub3D (e.g. when distributed in AIOI) does not include the LDraw archive libraries, LPub3D will prompt the installation user to download or select the LDraw library archives if they are not detected. This update allows portable distributions of LPub3D to exclude the official and unofficial LDraw library archive files. Note that if a portable distribution includes only the official LDraw library archive (complete.zip), LPub3D will automatically build the unofficial library archive (lpub3dldrawunf.zip) file from content in the LDraw\unofficial directory; however, subdirectory parts and p will be ignored so the created unofficial library archive will NOT contain the default unofficial library parts and primitives. To fully update the unofficial library archive file under this scenario, select Tools/Refresh LDraw Unofficial Parts from the LPub3D menu bar to update the lpub3dldrawunf.zip with the latest unofficial parts and primitives. 
Fix: Cover page attributes displayed outside of page (r853) 
 * Page attributes placed outside of page when displaying individual attributes. Attributes on both front and back cover pages were experiencing this behaviour. The behaviour is now corrected. Refer to features and enhancements for LPub3D 2.0.11.816.2  to review additional details on manipulating page attributes. 
Fix: Refresh open model file when preference changes (r852) 
 * Refresh open model file when "display all page attributes" and "generate cover pages" preference settings have changed. 
Fix: Unable to create a new line in text items - e.g. Model Description (r851) 
 * It is now possible to split text in text boxes and all editable page attributes - e.g. model description, LEGO disclaimer etc... When you select a text item, the cursor is placed at the very beginning of the dialogue. Use your arrow keys to move the cursor to the desired position of the dialogue. 
 To split a line simply hit the "enter" key on your keyboard. It is also possible to create a new line by inserting inserting the newline characters \n. 
 One can also add "quoted texts" in test items. Just like adding a new line, simply type " before and after the content you wish to quote. It is not necessary to enter an escape character \ but entering an escape character before the \" is also supported. 
Fix: The step number is slightly off of the page when using default settings (r850) 
 * Page header and footer width is now matched with the size and orientation of the displayed page. One can also change the "Relative To" settings from header/footer to page using the context menu/Move Step Number dialogue. For example, the step number on single step pages default placement is relative to the invisible page header - which can be managed in the page setup dialogue. Alternatively, step number placement on a single step page can be set relative to the page using the context menu as described earlier. 
Fix: Page movable and selectable in the graphics scene (r849) 
 * Page is now fixed and cannot be selected within the graphics scene. 
Fix: Drag and drop model file (r848) 
 * Open model file using drag and drop. Note that only one file at a time can be opened so dragging and dropping multiple files will only open the first file in in the list of selected files. 
 
LPub3D 2.0.15.846.2 
 
Features and enhancements 
------------ 
Fix: Reset step cache (r845) 
 * CSI (assembly) context menu item "Reset Step Assembly Image Cache." Clear and regenerate CSI .png (assembly) and .ldr (temp) files for the selected step. This context menu is only displayed for multi-step pages allowing the editor to refresh a specific CSI image on the page. 
Fix: Reset page cache (r844) 
 * Page context menu item "Reset Page Assembly Image Cache." Clear and regenerate CSI .png (assembly) and .ldr (temp) files for all assemblies on the current page. 
 This function will not reset PLI (parts) content. 
Fix: On reset all caches LPub3D returns to first page (r843) 
 * LPub3D will return to the page on which it was when reset all caches launched. 
Fix: Fade position lost on page refresh (r842) 
 * Refresh page (in the LDraw editor) and closing the preference dialogue will refresh the loaded model file after which the fade position is lost and the entire first step on the page is incorrectly faded. This behaviour has been corrected. 
Fix: INSERT MODEL meta places meta in the wrong place (r841) 
 * When there are steps after the last part-added step, the INSERT MODEL meta added by LPub3D is placed after the STEP meta instead of before it. 
Fix: Image banner removed from viewer window before export is finished (r840) 
 
LPub3D 2.0.14.838.2 
 
Features and enhancements 
------------ 
Fix: File reload after external source change breaks page drop-down combo dialogue(r837) 
 * When a file is reloaded after being changed by an external source, the drop-down menu for selecting a page doesn't work until after navigating using another method. 
Fix: Image orientation does not conform when page orientation changed to Landscape (r836) 
 * Image generation was not inheriting the proper page size values. 
Fix: Extra characters "" in margin meta and page size meta does not display the page size identifier(r835) 
 * Oops, allocated the page size identifier variable to the wrong meta - should have been allocated to page size meta instead of units meta (units meta is used for setting the margin). Consequently, the page size meta is missing the size identifier (A4, Letter, etc...) because the place-holder to pass the variable is not there. This must have happened during the patch process from the maintenance branch because it did not present during my tests. Both issues are now corrected. 
 
LPub3D 2.0.13.834.2 
 
Features and enhancements 
------------ 
Fix: Logging options added to Preferences (r832) 
 * Select logged attributes and logging levels. 
Fix: Prompt search directory settings reset (r831) 
 * Prompt to inform that the search directories have been reset after the search directory reset button is clicked. Restarting LPub3D is not required. Also changed menu items "Reset 3D Viewer Model Cache" to "Change Temp File Cache" and "Reset Image and Model Caches" to "Reset All Caches". 
Fix: Inconsistency between part counts in submodels and part counts in call-outs where multiple instances are involved (r829) 
 * For submodels, the PLI part counts reflect only one instance of the submodel, even if multiple instances are used in the same step. The instance count is correct, and the BOM has the correct total number of parts. With this update, sub-model pages displaying instance count now have a context menu option to display parts per step/page or not (total parts consumed by the number of instances indicated. 
 Previously, for callouts, you have the options (see context menu) to display parts list per callout (one instance) or not. When you select no parts list per callout, the PLI will show all the parts consumed by the total number of instances in the callout. If you choose parts list per callout, the PLI is moved to the callout and only the parts for a single occurrence of the callout is shown. The idea here is if you have 5 occurrences of the called out assembly, you'll need 5x the parts total, but only 1x parts are shown to indicate what you need to build an instance of the called out assembly. 
 On sub-model pages displaying the instance count, there is only one behaviour for PLI counts (the most intuitive) which is to display the parts list per step. This is intuitive because the primary role of the PLI is to show what you'll need to build an occurrence of the step shown - it is not the intention to mimic the BoM. Nevertheless, I added a context menu item to not display parts list per step and instead display total parts consumed by the number of occurrences of the submodel in the parent submodel/step. 
Fix: Page size and orientation processing update (r826/833) 
 * Further industrialization of the print/export module. This update streamlines the process and realizes some performance gains. There are some key changes. Notably, page orientation and page size are now mutually exclusive. This means when switching from Portrait to Landscape, accompanying the orientation meta with a transposed page size meta no longer required or managed. Here is an illustration: 
 Previous behaviour when editing a page size change required the following meta commands: 
 0 STEP 
 0 LPUB PAGE ORIENTATION LOCAL LANDSCAPE 
 0 LPUB PAGE SIZE LOCAL 11.0000 8.5000 
 Note that the page width and height have been transposed. Going forward, transposition of the page width and height when switching from Portrait to Landscape is automatically managed by LPub3D. 
 NOTE: This update is NOT backward compatible. An accompanying transposed page size meta to indicate the switch from portrait to landscape as shown above will be treated as a new page size meta for that page. Consequently, using this meta to 'switch' orientation will actually result in NOT switching the orientation as LPub3D will automatically switch again the switched page size meta. 
 If the user is only interested in changing the orientation, the proper meta command going forward will be: 
 0 STEP 
 0 LPUB PAGE ORIENTATION LOCAL LANDSCAPE 
 To help with accurately displaying the page size identifier in the setup and context menus, the standard page identifier is now appended to the page size meta command. For example: 
 0 LPUB PAGE SIZE 8.5000 14.0000 Legal 
 0 LPUB PAGE SIZE LOCAL 8.5000 11.0000 Letter 
 0 LPUB PAGE SIZE LOCAL 5.8000 8.3000 A5 
 0 LPUB PAGE SIZE LOCAL 5.8678 8.3456 Custom 
 Along with the width and height values, if the page size is non-standard, the identifier "Custom" will be automatically used. Additionally if an identifier is not present, the identifier "Custom" will automatically used. The page identifier is displayed in the Page Setup dialogue and Size/Orientation change context menu dialogue. 
 Also, the LPub3D print/export function no longer needs to parse the model file to capture, in advance, page sizes. This capture is performed during the existing page parse and load functions and is exposed to the print routines during printing/exporting. This change was necessary to better enable mixed-size page export/printing where it is necessary to 'look ahead' to get the next page's size and orientation parameters in order to configure the printer engine before processing the page. 
Fix: Expand INSERT MODEL meta command behaviour (r825) 
 * When using part fading LPUb3D will now process multiple INSERT MODEL commands rendering the CSI content at each command.  For example, if the instruction document includes different model attachments, the editor can now include a non-faded image of the entire model with each attachment. Here is an example of he proper command sequence when used in conjunction with BUFEXCHG: 
    0 BUFEXCHG B STORE 
	0 //...				    default model content... 
	0 STEP 
	0 BUFEXCHG B RETRIEVE 
	0 BUFEXCHG A STORE 
	1 0 445 -46 -10 1 0 0 0 1 0 0 0 1 attachment1.ldr 
	0 STEP 
	0 LPUB INSERT MODEL 
	0 LPUB INSERT PAGE 
	0 STEP 
	0 BUFEXCHG A RETRIEVE 
	1 0 0 0 0 1 0 0 0 1 0 0 0 1 attachment2.ldr 
	0 //STEP			    These last 3 lines are optional when editing the model file. 
	0 //LPUB INSERT MODEL	If they don't exist and fade step is ON, they will be automatically created by LPub3D 
	0 //LPUB INSERT PAGE 
Fix: The PNG output of a model with various page orientations is not correct (r824) 
 * Cleared page buffer before rendering each page. Also corrected a typo causing page range to sometimes not work for image exports. 
 
LPub3D 2.0.12.823.2 
 
Features and enhancements 
------------ 
Fix: LDView SnapshotSuffix to persist .png image generation (r820) 
 * As designed, LDView will use the last "Save as type" parameter set in the Save Snapshot dialogue for command line exports. I've added the command parameter -SnapshotSuffix=.png to force png image output in situation the user changes the LDView save as type from .png (e.g. exports a snapshot in .jpg format) while working outside of LPub3D. 
Fix: Industrialize pdf print/export preview dialogue(r819) 
 * Remove [Experimental] status from pdf print preview. Implement prompt to open pdf file after printing. Fixed launching "Pdf print preview" menu item disables the "Print to Pdf file" menu item (nothing happens when you click the Print to Pdf file menu item). This behaviour occurs only after launching Pdf print preview requiring an application restart to clear the behaviour. Fixed viewer print banner removed after the first printed/exported page. 
Known Issue: Some JPEG-compressed images types are not rendered as inserted image (r818) 
 * This was a Qt bug claimed to be corrected in Qt 5.5.1 (LPub3D uses 5.7); however, the issue seem to persist in Qt 5.7 also. Not all jpg images fail to load. The issue appear to be related to JPeGs with broken EXIF headers only. 
 
LPub3D 2.0.11.816.2 
 
Features and enhancements 
------------ 
Fix: Close model file (r810) 
 * Close model file and release all resources. 
Fix: LDraw editor comments not highlighted (r809) 
 * LDraw editor will now highlight LDraw line comments '//'. 
 Additionally, LDCad meta commands are also highlighted. 
Fix: Display part count (r809) 
 * Part count displayed on status bar at file load. 
Fix: Page size display in Page Setup dialogue does not show accurate size (r808) 
 * Conversion rounding error (between inches and centimetres) preventing the right page size index from being identified. Redesign to use single source (inches) converted dynamically between inches and centimetres when needed. 
Fix: Reload at file change prompt (r807) 
 * Users are now prompted to reload the model file when the loaded file is changed by an external source. With this fix, one can model the same file with multiple applications at the same time. 
Fix: Configuration parameters editor extra prompt to save before close (r807) 
 * LPub3D configuration file editor prompting to save changed content at the both the editor's window close and LPub3D main window close. This behaviour has been corrected to prompt only at editor window close. 
Fix: Part count gives wrong result. (r806) 
 * Setting an automatic piece count gives wrong count most of the time in an MPD with multiple submodels and multiple usages of certain same submodels. This behaviour is now corrected. However,the user will have to play a role in configuring her model file to accurately reflect the part count expected. This will undoubtedly require moderate knowledge of LDraw and LPub3D format/logic semantics. The implemented part count capabilities will aim to minimize the intervention of the user but; ultimately, the strength of the part count will depend on the integrity of the model file. 
 In LPub3D, three configuration patterns will determine if a part is counted: 
 1. The part file must contain a well formed part type meta. 
	Examples: 0 LDRAW_ORG Part, 0 LDRAW_ORG unofficial_part, 0 LDRAW_ORG unofficial part, 0 unofficial part 
	Note that LPub3D does not look at the file extension to distinguish between types. Therefore, one could have a file named foo.mpd which will be identified as a part if the above meta declaration exist. Conversely, if no declaration is present, foo.dat or foo.ldr will not be identified as a part. This feature can be useful when defining helper parts. For example, leaving out the type declaration in the file uparrow.dat will allow the user to include it in their instructions with out it being counted as a part. 
 2. Using the IGN (ignore) LPub meta will automatically exclude the part lines within from being counted. 
	For example: 
	0 LPUB PART BEGIN IGN 
	1 0 0 0 -120 1 0 0 0 1 0 0 0 1 outerrib.ldr 
	1 0 0 0 120 1 0 0 0 1 0 0 0 1 outerrib.ldr 
	1 71 -70.196 804.976 -165 -0.924 -0.383 0 -0.383 0.924 0 0 0 -1 32123a.dat 
	1 71 -218.11 743.75 -165 -0.707 -0.707 0 -0.707 0.707 0 0 0 -1 32123a.dat 
	1 71 -331.064 630.218 -165 -0.383 -0.924 0 -0.924 0.383 0 0 0 -1 32123a.dat 
	1 4 -392.285 322.436 75 -1.00023 -0.000246369 0 0 0 -1 0.000246369 -1.00023 0 arrow108.dat 
	1 4 -331.011 174.559 75 0 0 1 -0.999849 0 0 0 -0.999849 0 arrow108.dat 
	1 4 -217.888 61.481 75 0 0 1 -1.00023 0.000246369 0 -0.000246369 -1.00023 0 arrow108.dat 
	0 LPUB PART END 
	Note that parts in model subfiles within the IGN declaration will also be ignored. 
 3. There is now a part exclusion list under the user data directory ...extras/excludedParts.lst. 
 As with the other LPub3D lists, the part exclusion list can be edited from the configuration menu. 
 The exclusion list is effective in the scenario where one is using dynamically generated parts such as hoses, string, rope etc... Segment parts, e.g. LSynth's LSXX.dat parts, stickers, LDCad template segments etc... can be excluded from the part count by placing them on the exclusion list. 
Fix: Submodel instance count reflects all the occurrences in the subfile on initial display (r805) 
 * An example: when a model has 4x the same submodel, but 2 of those are used in step 10 and the other 2 are used in step 20, LPub3D will create 1x the submodel building steps with a 4x next to it. 
 LPub3D behaviour will now, optionally, display the submodel instance count reflecting only the number of instances used in the parent step. However, note that there is an efficiency trade-off to this change in the form of more redundant steps in your instructions. 
 For example, if I have 4 occurrences of a submodel in a 3-step model file and I consume 2 in step 1 and 1 each in steps 2 and 2, under the previous behaviour, you would indeed see 4 occurrences of the submodel on its last page - displayed while in parent step 1. The efficiency here is that for step 3 and 3 you will not again enter into the sub model's page(s) on the instructions because all 4 occurrences were already communicated to the user. LPub3D handles this by designating the submodel as being 'rendered' at the first occurrence for the entire model file. 
 For the new behaviour, the submodel is designated as 'rendered' at the first occurrence only for the step in which it is consumed. So subsequent occurrences in the same step will not enter into the submodel page(s). With the new behaviour, as LPub3D would only communicate 2 occurrences consumed in step 1, it will now be necessary to enter into the submodel page(s) on each step a submodel is consumed. This behaviour will not only communicate the remaining occurrences but it will also compel the user to navigate again and again the submodel's page(s). 
 For small models this may not be an issue but for large models or models where a submodel is large and used in many steps, the instructions will be overwhelmed with redundant information. 
 To balance this trade-off, I have added an option switch under Project Setup to enable or disable the consolidation of submodel occurrences at the first occurrence of the submodel (by parent model of course) in the instructions. 
Fix: Pdf preview progress bar (r803) 
 * Add progress bar to pdf preview dialogue. For large instruction documents it could be good to monitor the progress of the export process. 
Fix: Front and back cover page attribute placement (r802) 
 * By default cover page attributes are placed relative to each other (with one anchor placed relative to the page) on the front and back cover pages. Independent page attributes are by default placed relative to the page. The new behaviour will break the dependency (placing the dependent attribute relative to the page) if the attribute depended upon is not respecting its default relative to placement (e.g. ModelName relationTo has changed from Title to Page). I imagine this is more complex that it probably should be but the aim was to automatically place the attributes on model load so young/novice users would not have to fuss with even more complex configuration. 
 The quirk remaining is when you change placement relative on an attribute depended upon by another, the dependent attributes will obviously follow the position of the newly placed attribute. This may confuse users as it can be perceived as a bug. There are two ways around this when repositioning cover page attributes. The first way is to not change relative to placement, instead use the drag functionality to reposition the attribute and; the second way is starting from the bottom and working upward, set the dependent attribute(s) placement relative to the page using the Move "attribute name" context menu. 
 All attributes are optionally displayed. If a depended upon attribute display is false, its dependant attribute is automatically placed relative to the page. 
 Here is the the placement relativeTo table - any attribute not placed relative to the page is dependent: 
 
   * Front Cover Default Attribute Placements 
  ************************************* 
  *               Logo                *  (Bottom of Header) [Independent] 
  *                                   * 
  *   ModelName                       *  (Top Left of Title) [Dependent] 
  *   Title                           *  (Left of Page) [Anchor] 
  *   Author                          *  (Bottom of Title) [Dependent] 
  *   Pieces                          *  (Bottom of Author) [Dependent] 
  *   Model Description               *  (Bottom of Pieces) [Dependent] 
  *   Publisher Description           *  (Bottom of Model Description) [Dependent] 
  * 								  * 
  *            Cover Image            *  (Centre of page) [Independent] 
  *                                   * 
  ************************************* 
 
  * Header/Footer Default Attribute Placements 
  * *********************************** 
  * URL (Top Left of Page)            Email (Top Right of Page) 
  * *********************************** 
  * *                                 * 
  * *                                 * 
  * *                                 * 
  * *                                 * 
  * *********************************** 
  * Copyright (Bottom Left of Page)   Author (Left Bottom of PageNumber) 
  * *********************************** 
 
  * Back Cover Default Attribute Placements 
  * ********************************** 
  *               Logo               *  (Top of Page) [Independent] 
  *  Title                           *  (Centre of Page) [Anchor] 
  *  Author                          *  (Bottom of Title) [Dependent] 
  *  Copyright                       *  (Bottom of Author) [Dependent] 
  *  URL                             *  (Bottom of Copyright) [Dependent] 
  *  Email                           *  (Bottom of URL) [Dependent] 
  *  LEGO Disclaimer                 *  (Bottom of Email) [Dependent] 
  *  LPub3D Plug                     *  (Bottom of LEGO Disclaimer) 
  *  LPub3D Plug Image               *  (Bottom of Page) [Independent] 
  *                                  * 
  ************************************ 
Fix: Disable appropriate UI menu items if no document loaded (r801) 
 * Improve user interface guidance and efficiency. The aim is to better automate the user experience. 
Fix: Mixed page size and orientation export - pdf, png etc... (r801) 
 * The feature to set local page orientation works on screen, but not in the output in PDF or PNG. One is now able to successfully change both page size and orientation locally (at individual page). This capability applies to both pdf and image exports. 
 Additionally, there is now the [experimental] capability to preview your pdf output using the pdf preview menu item. Note that the preview dialogue uses the Qt native print engine (with pdf format output) to support print preview so mixed page size and orientation within the preview document is not well supported. For the moment, mixed page size and orientation documents will preview using the only the original page size and orientation. Output will be cropped and formatted accordingly. If your document does not contain mixed page size or orientation then the print preview functionality should present as expected. Also, note that printing usually consumes quite a bit of memory so, at this time, printing very large graphic intensive documents may experience abnormal termination. 
 Previously, LPub£D was using the default print engine (with pdf format output) which functions just as a physical printer. This means that as no one is likely to physically print different size pages during the same print run (at least not in standard printing), the pdf printer seemed unhappy when you try to switch page size while the printer is active. LPub3D now uses Qt's pdfWriter. Switching to the pdfWriter engine removes the limitation on both size and orientation while the 'printer' is active. 
Fix: Submodel instance count placement broken (r800) 
 *When using page number in alternate corners (like a book) the Submodel instance count is at the wrong place when it is on a odd page number on a single page submodel with a step group. Behaviour corrected and enhanced to detect when submodel instance count is on an odd or even page whereby the position is adjusted right or left of the step number accordingly. This automatic positioning is only available when the submodel instance count is placed relative to the page's step number - its default placement. 
Fix: Refactor fade directory logic (r799) 
 *Process fade directories upon application launch and file load more efficiently and effectively. 
Fix: Progress dialogue always stays on top (r797) 
 *Proper modality behaviour restored. 
Fix: Print/Export banner (image) rotation broken (r796) 
 *Banner rotation updated. Rotation broken by r791. 
Fix: Archive parts terminates on empty search directory folder (r795) 
 *Replace return (terminate) with continue. 
 
LPub3D 2.0.10.793.2 
 
Features and enhancements 
------------ 
Fix: Fix search directories not added to LDSEARCHDIRS env variable (r793) 
 *LDSEARCHDIRS is used by LDGlite to process LPub3D extra search directories. 
 
LPub3D 2.0.9.792.2 
 
Features and enhancements 
------------ 
-Fix: Align 3Dviewer and rendered csi image rotation (r791) 
 *The model loaded in the 3D viewer and its corresponding csi step image are now similarly rotated. 
-Change: Move fade part files folder to lpub3d data directory - was previously under ldraw/unofficial directory (r790) 
 *Remove potential conflict when ldraw disc library is located under Program Files(x86) or a user data directory which is different from the user LPub3D is installed under. For example, LPub3D may be installed under standard user 'foo' while the ldraw disc library is installed under user 'public' [or under Program Files (x86). In both cases, LPub3D will likely be blocked from creating fade part files under the ldraw directory - i.e. in Unofficial/fade. Moving the fade folders will ensure write access is always available as the fade part files folder will be under the LPub3D data directory (e.g. C:\Users\foo\AppData\Local\LPub3D Software\LPub3D\fade) 
 Note: If you are using an ldraw.ini configuration file which include paths to the fade/parts and fade/p folders, you must update the paths accordingly. Here is an example of what the new paths should look like if you are running an installed distribution: 
 C:\Users\[userid]\AppData\Local\LPub3D Software\LPub3D\fade\p 
 C:\Users\[userid]\AppData\Local\LPub3D Software\LPub3D\fade\parts 
-Fix: Fade parts functionality update (r789) 
 *Update logging, archive fade parts after model file load as necessary - previously only updated on application launch. 
-Fix: Move cache to root install folder for portable distributions (r788) 
 *Allow all runtime components of portable distribution to be contained within the folder structure of the distribution. 
-Fix: Extract archive library after download (r787) 
 *After archive library download, extract contents to defined LDraw disc library location. Archive libraries can be downloaded at application launch if no archive was found and at the tools menu where one can 'Refresh' the libraries at any time. The aim of this enhancement is to synchronize and automatically update both the archive and disc LDraw library content. 
 
LPub3D 2.0.8.785.2 
 
Features and enhancements 
------------ 
-Fix: Print/export 'page range' option output incorrect (r785) 
 *For print/export option "All pages," images are generated in numerical order. However, for option "Page Range," images are generated in "alphabetical" order for lack of a better description. If one selects pages 1-115, the order the pages are generated is 1, 10, 100, 11, 12, 13, 14, 15, 16, 17, 18, 19, 2, 20... The order is now as expected 1...10...100 etc... 
-Fix: Revert to MinGW distributions - for both x32 and x64 architectures (r784) 
 *Discontinue all MSVC LPub3D distributions. 
-Fix: Refactor loading model file into Ldraw editor window (r783) 
 *File load hangs for an unusual amount of time when loading a large model file. This behaviour appears usually when the LDraw editor tab is not in focus. If the file is loaded with the editor tab in focus, the file is loaded nominally. 
-Fix: Exclude fade directories from search directory list if fade step not enabled (r781) 
 *Improve just a little bit the performance during model file load. 
-Fix: Refactor adding parts to archive library (r780) 
 *Improved logging detail and added checks to not submit an empty search directory. 
-Fix: Log all status entries add date time stamp (r779) 
 *Capture all status bar updates to the log files. Increase log file size to 5Mb rotating across 5 files. Log files located at  Software/LPub3D/logs 
-Fix: Backup parameter files during install (r778) 
 *Backup user-editable parameter files that must be overwritten during installation of updates. This way, any additions created by the user will not be lost. However, it will be necessary to manually update the new parameter file with your additions. 
-Fix: Refactor fade step behaviour (r777) 
 *Update fadeStepColorParts.lst attributes to allow faster library parsing to generate static colour parts. 
 NOTE: FILE UPDATE REQUIRED. fadeStepColourParts.lst file updated with new required column so it is necessary to update your installed file. LPub3D will automatically backup and overwrite the existing file during installation. 
-Fix: Adjustable renderer process timeout (r776) 
 *All the user to manage the amount of time to keep alive the renderer process. The default is 6 minutes but can be changed between -1 which is run indefinitely and 99 minutes. For high definition using POV-Ray, rendering process time can easily exceed the default. This setting is located at Preferences/Rendering/Process timeout. 
-Fix: Reload archive libraries into memory (r775) 
 *On model file load, do not reload library if no new parts discovered. LPub3D sweeps the defined search directories upon file load. This update makes a little more efficient the load process. 
-Fix: Update aboutdialog display version of Qt (r774) 
 *Display version of Qt from the platform versus hard coded. 
-Fix: Compile on MinGW x64 (r773) 
 *Convert int to intptr. 
 
LPub3D 2.0.7.770.5 
 
Features and enhancements 
------------ 
-Fix: Elapsed timer on file open (r771) 
 *Display elapsed time to load a file. 
-Fix: Archive library copy function not working if [empty] library directory exist (r770) 
 *If user data libraries directory exist, library copy from installed base is ignored. This is an issue if there are no libraries in the library directory. The correct behaviour is to verify that libraries exist and copy if they don't. 
-Digitally sign LPub3D executable distributions (r769) 
 *Secure installation content and reduce the likelihood of triggering antivirus quarantine. 
-Fix: Inconsistent fade behaviour when using BUFEXCHG parts and added parts in the same step (r764) 
 *Behaviour previously used the size of the previous step's CSI to determine the fade position index of the current step in all cases. This approach could lead to an inconsistent fade position after retrieving a buffer. Behaviour corrected to use the size of the previous buffer parts list (versus the CSI) to determine the current step's fade position when BUFEXCHG RETRIEVE meta command is used. This approach removes the necessity to follow the BUFEXCHG RETRIEVE meta command with a STEP/ROTSTEP meta command to process the fade sequence which will unnecessarily render the buffered items twice, in the buffered view and the modelled view. Usually only the buffered view render is desired in the current step (that's why the assembly is buffered in the first place) but the modelled view CSI should be carried forward to the next step. Here are two examples: 
 Example 1: No unbuffered parts in step 1, render buffered skeleton with arrow in step 1 but render only modelled skeleton faded and the current parts in step 2 
	0 LPUB ASSEM MODEL_SCALE LOCAL  0.6500 
	0 BUFEXCHG A STORE 
	0 GHOST 1 0 201.2 -844.25 0 1 0 0 0 1 0 0 0 1 skeleton.ldr 
	0 BUFEXCHG B STORE 
	0 BUFEXCHG A RETRIEVE 
	0 LPUB PART BEGIN IGN 
	0 GHOST 1 0 201.2 -960.25 0 1 0 0 0 1 0 0 0 1 skeleton.ldr 
	0 GHOST 1 4 -131.2 -216.25 -70 -1 0 0 0 1 0 0 0 -1 arrow88.dat 
	0 LPUB PART  END 
	0 STEP 
	0 LPUB PLI CONSTRAIN LOCAL HEIGHT 5.67 
	0 LPUB PLI PLACEMENT LOCAL LEFT PAGE INSIDE 0.0115693 -0.118771 
	0 BUFEXCHG B RETRIEVE 
	1 0 -130 -232 -70 -1 0 0 0 1 0 0 0 -1 3069b.dat 
	1 0 -130 -232 70 -1 0 0 0 1 0 0 0 -1 3069b.dat 
	0 STEP 
 Example 2: Unbuffered (modelled) parts in step 1, render hobspine, crossbrace, and outerrib with arrow (buffered) in step 1 but exclude arrow and show faded, step 1 modelled parts plus current parts in step 2. Step 1 terminates with ROTSTEP 
	0 GHOST 1 0 0 0 0 1 0 0 0 1 0 0 0 1 hobspine.ldr 
	0 LPUB CALLOUT BEGIN 
	0 LPUB CALLOUT POINTER BOTTOM_LEFT 0.608 0.763 0 
	1 0 0 0 0 1 0 0 0 1 0 0 0 1 crossbrace.ldr 
	0 LPUB CALLOUT PLACEMENT RIGHT ASSEM INSIDE 0.41159 0.062474 
	0 LPUB CALLOUT END 
	0 BUFEXCHG A STORE 
	1 0 0 0 -40 1 0 0 0 1 0 0 0 1 outerrib.ldr 
	1 71 -70.196 804.976 -55 -0.924 -0.383 0 -0.383 0.924 0 0 0 -1 32123a.dat 
	1 71 -218.11 743.75 -55 -0.707 -0.707 0 -0.707 0.707 0 0 0 -1 32123a.dat 
	0 BUFEXCHG B STORE 
	0 BUFEXCHG A RETRIEVE 
	0 LPUB PART BEGIN IGN 
	0 GHOST 1 0 0 0 -120 1 0 0 0 1 0 0 0 1 outerrib.ldr 
	0 GHOST 1 71 -70.196 804.976 -165 -0.924 -0.383 0 -0.383 0.924 0 0 0 -1 32123a.dat 
	0 GHOST 1 71 -218.11 743.75 -165 -0.707 -0.707 0 -0.707 0.707 0 0 0 -1 32123a.dat 
	0 GHOST 1 4 -70.196 804.976 -95 1.00023 0.000246369 0 0 0 -1 -0.000246369 1.00023 0 arrow88.dat 
	0 LPUB PART END 
	0 ROTSTEP 0 75 0 ABS 
	0 BUFEXCHG B RETRIEVE 
	0 LPUB PLI CONSTRAIN LOCAL HEIGHT 3.51333 
	1 0 -378.303 402.398 -50 0 1 0 -1 0 0 0 0 1 3460.dat 
	1 0 -378.303 402.398 50 0 1 0 -1 0 0 0 0 1 3460.dat 
	0 STEP 
-Fix: LDView single call render crash on multi-step page generation (763) 
 *Crash if multi-step page's steps contain more than PLI and CSI components. Corrected. 
-Fix: Preference dialogue version change log cleared on update check when there is no available update (r762) 
 *If no update available, ignore updating the change log dialogue. 
 
LPub3D 2.0.6.761.3 
 
Features and enhancements 
------------ 
-Fix: Set radial and conical background gradient parse fail with 'Malformed background...' (r759) 
  *Parse fail for radial and conical gradient meta commands. Linear, radial and conical gradients are all now working as designed. 
-Fix: Scale in Page Globals Setup dialogue not working (r756) 
 *Cover Image and Logo double spin control not working. Issue corrected. 
-Fix: Save and restore application window state and geometry (r755) 
 *Was causing crash on launch before update to Qt5.7. 
-Fix: Application crash on launch (r754) 
 *Update to Qt5.7 on MSVC2015 and MinGW5.3. There must have been a big, nasty bug in Qt 5.5/5.6 because the code that consistently generated the crash immediately resolved upon update to Qt5.7 
-Fix: Crash on application close on Windows7 (r753) 
 *Expected scoped pointer main window to destruct all children on close but it seems like 3d viewer application and mainwindow were not treated as children and were not deleted at application close by the scoped pointer on Windows7 machines. Manually delete 3D viewer application instance and mainwindow at LPub3D termination. 
-Fix: Substitute parts use only file name; file path not required (r752) 
 *When editing substitute parts list, it is not necessary to enter the absolute file path for the substitute file. Just entering the substitute file name will be sufficient. 
-Fix: Title annotations displays when only Freeform annotation selected in setup preference (r751) 
 *Logic processed title annotations when it should not have. Corrected. 
-Fix: setGeometry: Unable to set geometry 600x800 warning message (r749) 
 *Use QDesktopWidget.availableGeometry(this) setting to support single and multi-screen configurations. 
-Fix: Parameter file edit window highlighting part description containing '#' (r748) 
 *Highlight only lines where first character is '#'. 
-Fix: Generate fade colour parts list crash (r747) 
 *Redesigned functionality to process parts from archive libraries (unofficial and official) versus LDraw disc directories. This approach improves performance and reliability as all parts, including those from additional search directories, are collected in the archive libraries. Working with archive files is much faster than working with disc directories. 
 
LPub3D 2.0.5.744.3 
 
Features and enhancements 
------------ 
-Fix: Portable distribution create and populate user data directory when installed under Program Files/(x86) (r744) 
-Fix: Revert to deposit LPub3D icons in Programs menu (versus startup menu) (r743) 
-Fix: Remove MAINWINDOW registry group if exist (r742) 
 *I believe the settings in this group are contributing to the intermittent crash at startup. 
-Fix: LDConfig load order; first, LDraw directory; second, extras directory; third, resource cache (r741) 
-Fix: Automatically load ldglite during installation/application launch (r740) 
 
LPub3D 2.0.4.737.2 
 
Features and enhancements 
------------ 
-Fix: Release Windows MinGW x32 builds (r737) 
 *Update deployment utiliites to produce both MinGW and MSVC builds. MinGW will only support x32 architecture for the moment. 
-Fix: Search directories for LDGlite (LDSEARCHDIRS) not loaded as expected at startup (r735) 
 *Loading the LDGLite search directories at startup occurred out of order (before general search directories) so the LDGlite routine did not pass the conditional test to actually load search directories. This behaviour would cause a crash if parts to be loaded were in the standard LDraw official or unofficial directories - for example under ..\Unofficial\myParts - and LDrawini was not in use. LDGLite would not be able to find the part and; consequently, would not be able to generate a part image. 
-Fix: Fade steps skips the second step in a model. Fading starts on the third step. (r734) 
 *No fade parts index generated on the first step because nothing was faded; however, we still need an index to know where to start on the second step. Fade step routine fixed to generate an index as long as there are valid parts in the step. 
-Fix: Installer program configured to deposit a master copy of user data (libraries, lists, etc...) in the installation root directory. (r733) 
 *Allow user data creation at initial launch. Upon initial application launch, if user data does not exist, it will be created. This will address the issue of Windows standard users not having access to user data after installation. Additionally, this design allows for multiple users on a single machine to have their individual user settings and data. 
-Fix: Set progress dialogue to non modal. (r732) 
 *Prevent the progress dialogue from blocking input to other windows. 
-Fix: Data directory installed under Administrator AppData path instead of logged in user which is likely to be a standard user (r731) 
 *User data - LDraw archive libraries, logs, extras and other updatable data items - will be installed at initial application launch by default. Because Administrator privileges are required to install LPub3D, user data installed during installation will be deposited under the Administrator user's AppData path. This data will not be accessible to standard users. User data can be installed during application installation as a checked option. This option may be desirable if the logged in user installing LPub3D is also the Administrator. If user data is installed during installation, user data for standard users will be automatically created during initial application launch. On initial application launch, the standard user will be given the options to select, copy (from the installation directory) or download the LDraw archive libraries. (Known Issue: Standard user icons are not being generated at the moment. Also, The uninstall routine will not remove standard user data created at application startup. I'm still working on improving the deployment package to handle these items). 
 
LPub3D 2.0.3.730.2 
 
Features and enhancements 
------------ 
-Change: Check for update settings are now enabled by default. Previously, it was necessary to configure update settings in the Preferences/Other tab before one could visually confirm an update check. (r722) 
-Fix: Warnings are displayed when there are no unofficial subdirectories under the LDraw directory. (r723) 
 *When no search directories are defined (i.e. No Unofficial or Models directories exist) and the user opens the Preferences dialogue, teh LDraw Content Search Directories dialogue will validate an empty dialogue with a warning that the 'entry' is an invalid search directory. In such case no warnings should be displayed. 
-Fix: Installation program presents options to delete 'old' library directory on new installation when no old directory existed. (r724) 
 *Comparison of old and new are not the same evaluated to true. Comparison improved to check that old is actually a directory also. 
-Change: Preferences/Other/Check for updates/Version now presents all valid updatable versions in a dropdown list. (r725,r728) 
 *Manage better the update dialogue. Restrict entries to only valid update versions. 
-Fix: Crash when last line in main model of mpd file is a part type line - i.e. line starts with 1 to 5. (r726) 
 *This behaviour will be seen when the user loads a model file without the meta tag '0 STEP' or '0 NOFILE'. 
-Fix: Export and PDF generation produces "Failed to create CSI" and does not produce model images in the generated document.(r727) 
 *Temporary testing code blocked the creation of CSI images - my apologies:-( 
 
LPub3D 2.0.2.721.2 
 
Features and enhancements 
------------ 
-Fix: Add all Visual C++ dependencies to installation and portable distributions including VC++ 2015 re-distributable runtime libraries (r720) 
 *Repackaged all distributions to incorporate all MSVC 2015 required dependency libraries. The Visual C++ Re-distributable for Visual Studio 2015 is also included in the portable distributions. For the executable installation distribution, the installation program will check if the required libraries exist before silently installing the respective Visual C++ re-distributable. 
 -Known Issue: Storing and retrieving the screen pos[ition], size, state and geometry settings appear to be causing intermittent crash on startup - at the end of the splash screen display. (r718/r719) 
 *This functionality has been disabled for the moment while I investigate. This unexpected behaviour was introduced with the Qt5.6/MSVC 2015 development platform. The change you may notice is that the application no longer starts on the screen you last close it. Instead, it will will always start at the same location. While I have experienced this behaviour on a multi-screen display configuration, there are reports that this behaviour also exist on single-screen displays. 
-Fix: Disable search directory validation in Preferences dialogue - temporary workaround (r721) 
 *Warnings are displayed when there are no unofficial subdirectories under the LDraw directory. In such case no warnings should be displayed. 
 
LPub3D 2.0.1.717.2 
 
Features and enhancements 
------------ 
-Fix: In support of archive library move to AppData (see r707), the installation process will delete the 'old' LDRaw library archive directory even if it is actually the new directory. For example this can be reproduced if one attempts to reinstall LPub3D where the actual 'old' directory would have been deleted during the initial installation. The installation will now compare the 'old' directory to the new one and present the user the option to delete if the comparison does not match. (r715) 
-Fix: At application launch, the 'Check for updates' does not detect the installed version. As a result, if the user performs a check for update or update checks are set to automatic, the user is presented with a message dialogue stating a new update version is available when in fact this is not the case. The correct message dialogue is now presented. Runaway eventloop when newest version is same as installed version. (r716) 
 
LPub3D 2.0.0.714.2 
 
Features and enhancements 
------------ 
-Up to 60 percent increase rendering speed with configuration to render multiple files using a single call to LDView. 
 *All PLI (part list/BOM) parts for a given step are rendered in a single call versus individually. For CSI (Step models), all multi-step images on a page are rendered in a single call including callout(s). Single step page images are rendered with a single call for all model images including those in callout(s). This new configuration will default as checked in the preferences dialogue. 
 *To achieve this behaviour, input files (csi.ldr, pli.ldr) are now uniquely named because rendering multiple files is done by using -SaveSnapshots=1 instead of -SaveSnapshot=somefile.png and then listing all the LDR files at the end of the command line. There is no control over the output file names. Instead, LDView will automatically use the input base filename changing only the output filename extension from .ldr to .png. 
 *Enabling this feature is optional and can be selected on the Configuration/Preferences/Rendering tab by checking the box 'Use multiple files single call rendering' in the 'LDView is installed' group box. LDView must be installed and configured to enable this option. 
 *Notice: As this feature required a significant rewrite of the core image generation logic, it is likely to generate some unexpected behaviour as not every scenario has been tested. Please report any unexpected behaviour. Contact details can be found under the Help/About menu. 
-Move LPub3D Ldraw archive libraries to AppData and rename unofficial library to lpub3dldrawunf.zip (r707) 
 *Archive libraries loaded automatically by ldraw during ldraw installation and is also distributed with portable media 
 *Archive libraries stored in user data (i.e. on Windows user/AppData/Local/Lpub3D Software/Lpub/libraries) 
 *LPub3D does not use parts from LDraw directory and ldconfig will fallback to the imbedded resource version if no LDraw directory is detected (This feature is not yet fully enabled. It is targeting a future enhancement) 
 *With exception of 'p' and 'parts', parts stored under .\LDraw\Unofficial are automatically added to lpub3d archive during application startup 
 *Lpub3d expects the official and unofficial library archive in the same directory. 
 *Lpub3d will prompt for archive file on startup if none is detected in the default expected location - this feature is targeted to support portable media and repackaged distributions (i.e. AIOI installations) 
 *If portable media installed in Program Files/(x86) folder, LPub3D will warn that it cannot place writable files at the default data location (folders under the installation directory) because UAC will prevent update access. This is useful for repackaged distributions (i.e. AIOI installations) 
-Multi-step callouts are now movable (r656) 
 *Callouts on multi-step pages are now freely movable on the page. 
-Add menu option to download official LDraw archive - unofficial archive was already available in v1.3.5 (r708) 
 *You can refresh both your official and unofficial LDraw library archives from the UI - As you may see from reading the change log, the aim is to over time allow LPub3D to be completely autonomous while maintaining it's ability to detect and consume unique and individual LDraw environment configurations. 
-Add callouts, refactor and optimize LDView single call image generation, see r683,r684,r685 (r698) 
 *The LDView 'Single Call' rendering performance improvement will address parts list and model rendering for single step page, multi-step page and callouts - including divided pages/callouts. For example, a callout with 6 models, divided into 3 sections will send a single call to LDView to render all 6 model (CSI) images. 
-Add progress bar to mpd/ldr file load (r690) 
 *Users can now see the progress of loading models. This is particularly useful for large models or models which include a large number of lines due to generated flex-parts etc... 
-Enable 'Use multiple files single call rendering' for LDView from Preferences/Rendering/LDView is installed/Use Multiple files single call rendering. (r687) 
 *LDView 'Single Call' rendering performance improvement can be selected or unselected from the preferences dialogue. Although I tested the as many scenarios as I can think of. If this new feature encounters some unique model file configuration that causes unexpected behavior, the user can revert back to the legacy functionality if s/he so desire. 
-Increase PLI (Part list/BOM) and CSI (Model) rendering speed with LDView using -SaveSnapshots=1 (r683/r684/r685) 
 *'Single Call' performance improvement for LDView 
-Redesign software and library update functionality (r710) 
 *Update architecture improved to allow archive library download during installation if no library is defined. This feature is positioned for mobile/packaged distributions (i.e. AIOI) distributions. 
-Display application load progress during splash screen display (r676/r709) 
 *User can follow the application loading progress during startup launch 
-Add context menu to pages without steps - e.g. Cover Page, BOM Page (r681) 
 *Pages without steps (e.g. Cover pages, BOM pages etc.) can be modified using the context menu. For example, to change background colour. 
-Add missing context menu icons (r680) 
 *Small beautification enhancement - all context menu items now show a representative icon - this can be helpful when generating user guides for example. 
-Supress rotateIcon context menu item if rotate icon already inserted for step (r670) 
 *If a step already has an inserted rotate icon, the page/callout context menu will not present the option to add a rotate icon. Note: The option to delete a rotate icon presents from the context menu of the rotate icon itself and not from the Step/Callout's context menu. 
-On a single-step page, place PLI (Parts List) on top of CSI (Model) images (r664) 
 *If a CIS (model) overlaps the PLI (parts list) the parts list will be presented on top so the instructions consumer can see all the parts implicated for the step presented. The reverse was previously the case. 
-Upon reset image and model caches, reload current file, return to first page (r663) 
 *Reset cache options which clears all cache components (ldr, images, 3D views) will also reset the loaded file to the first page. 
-Unique splash 3D model displayed during pdf printing, png, jpg and bmp image export (r657) 
 *Updated the 3D Viewer splash to reflect the format of output being generated - so an image depicting a pdf file will show when generating a pdf file and so on... 
-ldglite update to 1.3.1 executable with -2g,2x option hardcoded for sharper images with offscreen rendering (r655) 
 *Incorporated the new ldglite renderer with 2x sampling for improved image quality 
-Disable Clear Cache menu button when no file is loaded (r686) 
 *Just a little poka yoke. The cache locations are specific to the file loaded, so it does not help to have this button active when no file is loaded. 
-Force to empty the cache before creating a PDF (r654) 
 *Added option to empty the image ldr and image cache before printing. With this feature the user can select the option on the print configuration dialogue to clear the cache and regenerate images as the print/export job executes. 
-Synchronize 'prev', 'next' and 'goto' page menu items (r653) 
 *User can enter directly any page number within range into the menu dialogue. Clicking either the Previous or Next button will navigate to the page indicated regardless of if the page is the next increment backward (for Previous) or forward (for Next) or a page further backward or forward. The user can still hit the enter key to navigate to the indicated page - if not the current page of course. 
-Supress rotateIcon from CSI (model) item context menu if we have a callout and the callout assembled (r652) 
 *The menu option to insert a rotate step icon is not presented for assembled callouts. 
-Select local page size and global and local page orientation - Portrait and Landscape (r518) 
 *Note: When manually editing the model file with either page size or orientation, it is recommended to insert both the size and orientation metas together. For example, even if you are only interested to add a page size, you shold update your file like the example 
 below - obviously selecting your own size values and orientation. 
 0 LPUB PAGE SIZE GLOBAL 8.2677 11.6929 
 0 LPUB PAGE ORIENTATION GLOBAL PORTRAIT 
-Change: Page background context menu rearranged. "Change page background" and "Change Page Size or Orientation" now appear at the end of the menu list because they are likely to be least often used. (r641) 
-Change: Point online manual to LPub3D content - was previously pointing to legacy LPub (r517) 
-Refactor: Move library archives to AppData stabilization and robustness (r711) 
-Refactor: Optimize fadeStep routines; change LDView logging details (r695) 
-Refactor: Replace 0x050000 with QT_VERSION_CHECK(5,0,0) (r660) 
-Refactor: Remove stretch/tile logic from coverImage management (r659) 
-Refactor: Update CSI image mousePressEvent logic. (r640) 
-Refactor: Update file load progress messages (r636) 
-Refactor: Rearrange printToPdfFile page count (r632) 
-Update: Clear 3D Window when there is no model to display - e.g. for cover or inserted pages (r701) 
-Update: Set download dialogue header to Library Updater when downloading library - otherwise Software Updater (r700) 
-Update: AboutDialog window recognizes and displays Win 10 and OSX El Capitan(r665/r668/r669) 
-Update: ldglite hard-coded default directory setting to ldglite1.3.1(r623) 
-Update: 3DViewer minifig settings moved to ini file - LeoCAD Changeset 1870 (r617x) 
-Fix: No image after initial generation when renderer other than LDView selected (r704) 
-Fix: Set ldr load file to unofficial item by default (r691) 
-Fix: Load inline submodels break (r688) 
-Fix: Remove libpng warning: iCCP: known incorrect sRGB profile (r678) 
-Fix: Convert special characters (copyright and trademark) from Wide Char to UTF8 for MSVC build (r677) 
-Fix: Remove final colour model if exist when Fade Step is not enabled (r674) 
-Fix: Clear cache when turning fade on/off (r674) 
-Fix: FadeStep and preferCentimeter setting mixmatch (r674) 
-Fix: Search directories not updated when directory added to Ldraw.ini (r673) 
-Fix: When background is transparent context menu functionality is lost (fix is a hack which sets the bg-color to white with an alpha of 1.) (r672) 
-Fix: When a CALLOUT allocation is changed, if you right-click a model in the callout and not the callout itself, the ALLOC meta is placed after the CALLOUT END and has no effect - meta appended but should be inserted (r650) 
-Fix: Converting an assembly to a part results in a parse error when there are spaces in the file name (r649) 
-Fix: If a divided STEP GROUP allocation is changed from vertical (Display as columns - default) to horizontal (Display as rows), selecting again Display as columns has no effect - meta appended but should be replaced (r648) 
-Fix: When the "Redraw" icon is clicked on the LDraw File Editor window, the file editor resizes to 255x190 pixels (r647) 
-Fix: Split BOM duplicates one part onto current and subsequent BOM pages (r646) 
-Fix: Inserting a front cover page when the current first page is a multi step page (r645) 
-Fix: Bug when using callouts in Multistep sequences. When you place your callout right from assembly, it appears on the left side. When you place your callout bottom, it appears on the top. (r643) 
-Fix: wrong text when you export to PNG the window title says "Print to pdf" (r638) 
-Fix: When publishing instructions with the option 0 LPUB PAGE BACKGROUND TRANSPARENT a drop shadow layer was added (r637) 
-Fix: Remove -w1 from default ldglite parms (r629) 
-Fix: Periodic multi-step crash - 3DViewer image file line number mismatch (r628) 
-Fix: Control manual page number entry (r627) 
-Fix: Cleanup 'Copyright' and 'Trademark' unicode (utf8) chars on MSVC2015 build (r622) 
-Fix: QPainter alphaChannel management - use setCompositionMode (r619/r620) 
-Upgrade: With upgrade to Qt5x, moved to MSVC 2015 release builds to continue providing x85 and x64 builds as MinGW does not officially support x64 on Windows 
-Upgrade: Updated development platform to Qt 5.6.1 (MSVC 2015) (r613) 
-Upgrade: Updated Qt logging framework from Qt4x to Qt5x (r610) 
-Upgrade: Updated development platform to Qt 5.5.1 (MinGW) (r608) 
 
LPub3D 1.3.5.615.2 
 
Features and enhancements 
------------ 
-Fix: Pdf output restored to vector graphics - was being formatted as bitmap because conflicting setting was exposed during printing. (r615) 
 
LPub3D 1.3.4.591.2 
 
Features and enhancements 
------------ 
-Fix: During installer installation, prompt user to overwrite existing configuration files (r591) 
 
LPub3D 1.3.3.590.2 
 
Features and enhancements 
------------ 
-Fix: Crash when pieceinfo is null - this occurs when a file has no FILE meta and is imported as an ldr (versus an mpd).(r575) 
-Fix: Periodic crash when changing margin of assembly (CSI) in multi-step page (r577) 
-Fix: Periodic crash when adding divider to multi-step page or callouts (r577) 
-Fix: Periodic crash every time a second successive rotation icon is added to multi-step page (r577) 
-Fix: If using LPub3D archive distribution (no installer), use distribution's extras folder instead of creating one in AppData (r579) 
-Fix: Print/export dialogue progress bar (r585) 
-Fix: Upon "Add assembled image to parent page" a rotation icon is added to the callout if rotation icons were present in the callout step(s). Assembled and rotated callouts will not display rotate icons on the parent page. Only unassembled callouts will display rotate icons if present in the callout step(s). (r587) 
-Fix: 2 page refreshes when Parameters menu item is accepted - only a single refresh needed. (r588) 
 
LPub3D 1.3.2.563.5 
 
Features and enhancements 
------------ 
-Fix: PLI Parts annotation restored to short value (r555) 
-Fix: Control manual page number entry. (r562) 
-Fix: Remove silent_alloc which would trap the Callout meta LPUB CALLOUT HORIZONTAL/VERTICAL and throw a parse error. 
 However silent_alloc was not fully implemented and does not serve any current purpose. 
 The correct meta to allocate a Callout Horizontally or Vertically is LPUB CALLOUT ALLOC HORIZONTAL/VERTICAL (r563) 
 
LPub3D 1.3.1.516.3 
 
Features and enhancements 
------------ 
-Fix: Update ldglite hard-coded default directory setting (r505) 
-Fix: Remove hard coded reference to LPub3DViewer-Library folder - this was added in 1.3.0 unofficial archive refresh functionality (r506) 
-Enhancements (r507) 
-Fix: Add pliSubstituteParts.lst to media build - sorry, I forgot to include in the NSIS build script:-( (r515) 
 
LPub3D 1.3.0.504.2 
 
Features and enhancements 
------------ 
-Add dialogue to print or export to image all pages, current page and custom range of pages (e.g. 1,3,5,7-9) 
-Add ability to detect additional ldraw content search directories using ldrawini c api 
 I implemented the ldrawini c api to maintain compatability with LPub3D 3rd Party renderers - LDView, L3P(PovRay) and Ldglite. Additional directories must have either the same tree as LDraw Unofficial directory (i.e. parts and/or p subdirectories...) or alternatively, content can be deposited at the root of the additional directory (i.e. C:/ldrawFiles/*.dat). Content from all defined ldraw search directories are archived in the ldrawunf.zip archive and loaded into memory - enabling access to the 3DViewer. 
 If no ldraw.ini file is detected. LPub3D will automatically search all subdirectories under the ldraw/Unofficial directory - except directories p and parts. Unofficial subdirectories p and parts as well as official p and parts subdirectories are never searched because they are aromatically loaded during default behaviour during startup. 
 There are 2 ways to define search directories: 1. using the Ldraw.ini file (there is now a menu button to edit the ldraw.ini file) and 2. editing the 'Ldraw Content Search Directories text edit dialogue under the 'Other' tab in Preferences. If you are using an LDraw.ini file, the preferences dialogue will be read only - you must use the menu edit button under 'Configuration' to edit the ldraw.ini file. The ldraw.ini edit button only appears if a ldraw.ini file is detected. If you are not using ldraw.ini, it is possible to add,remove and reset to the default search directories in the Preferences tab. 
 ldglite renderer updated with the ability to process additional directories beyond official/unofficial parts, p and Model. I implemented this 
 enhancement to allow all 3 LPub3D renderers(LDView, Ldglite, L3P/PoV Ray) the same functionality supporting additional ldraw content search directories. LPub3D now passes 2 env variables to ldglite - LDRAWDIR and LDSEARCHDIRS. LdView and L3P already uses the ldrawini.c library. They can also be configured to detect additional ldraw content search directories if no ldraw.ini file is configured. I also upgraded ldglite's openGL API from glut (deprecated) to freeglut 3.0 released in June 2015. Ldglite os not versioned at 1.3.0 (from 1.2.7). 
-Add ability to manage additional ldraw content search directories whether using Ldraw.ini or not. 
 If not using Ldraw.ini file, automatically detected search directories are limited to those under the Unofficial directory. The user has the abilty to exclude and reset search directories within this edit list. Unofficial P and Parts directories are automatically excluded from the search directory list as they are loaded automatically by the application. 
-Add Rotate Icon - indicate that the builder should "flip" the model 
-Add line type attribute to border configuration 
 0=none,1=solid,2=dash,3=dot,4=dashDot,5=dashDotDot. So an old meta line like this: 
 0 !LPUB PLI BORDER GLOBAL ROUND Black 0 15 MARGINS 0.472439 0.07 should be updated to this: 
 0 !LPUB PLI BORDER GLOBAL ROUND 1 Black 0 15 MARGINS 0.472439 0.07 
-Add PLI/BOM part substitution - substitute modeled part in PLI/BOM with alternate 
 This feature is useful when you have a modeled part (e.g. Power Functions Light) that will 
 take alot of space in the BOM/PLI, you can substitute the modeled version with an alternate 
 representation that is suitable for the PLI/BOM view. This feature is complementary to LDCad's 
 template functionality which allows you to model adjustable parts as needed. To use this 
 functionality, simply edit the substitution list from Configuration= BOM/PLI Substitute Parts List 
-Add LDCad PART/UNOFFICIAL PART meta to recognize LDCad template generated parts 
-Add gradients to background options 
-Add Change local page background - colour, gradient, picture, submodel, none 
-Add memu item 'Refresh Unofficial Parts' which downloads and replaces the ldrawunf.zip archive 
 in the  Ldraw/LPub3DVoiewer-Library. LPub3D places all search directory parts in the ldrawunf.zip archive so they 
 can be made available for the LPub3D Viewer. This feature allows you to reset the archive file to 
 it's latest default content if desired. The ldrawunf.zip unofficial archive is used, along with the complete.zip, 
 by the 3DViewer. 
-Add menu item 'Reset Fade Files Cache' which deletes all generated fade files. Fade files automatically 
 generated as needed when you open a model with the 'Enable Fade Steps' preference option checked. 
-Update 3DViewer to LeoCAD build 1867 
-Remove PartsList class, use instead lcPiecesLibrary class to verify parts and capture part title. This is a consolidation to 
 improve the application's performance. 
-Move process fade colour parts to separate thread. 
-Move fade parts directory from under LDraw/Unofficial/parts and LDraw/Unofficial/p to as single directory 
 under LDraw/Unofficial. So from this version of LPub3D, the fade directory will be autogenerated and populated 
 as LDraw/Unofficial/fade. Old fade directories under Unofficial/parts and p must be manually removed if desired. 
-Redesign color part list and archive classes - rename and separate generate color parts list 
-Cosmetic and performance updates 
-Fix: Changing step number attributes on multi-step pages are now working 
-Fix: PLI/BOM sort routine, sort on 'part colour' part(s) appear out of place relative to 
 part size and colour. 
-Fix: Do not create instruction page(s) for unofficial part 
-Fix: Create s/8/48 subdirectory in lpub/tmp directory when needed. This fix will resolve the issue of LPub3D not being able to create inline unofficial subparts and 8/48 primitives when rendering models where these parts are defined in the model file. 
-CHANGE: In previous versions of LPub3D, custom and fade parts were loaded under the Unofficial directory allowing detection by all renderers and the 3D viewer. From this version of LPub3D (v1.3.0), the fade directory will reside at the root of the the Unofficial directory. Custom content added to Unofficial P and Parts directories will not detected by LPub3D. 
-CHANGE: Change part count routine to use ldraw archive files to look at 'LDRAW ORG...' part type meta tag. I think there are still some issue with 
 this routine however - especially with large complex models using in-lined unofficial parts that may not be in ldrawunf.zip 
-CHANGE: Change 'Reset All Caches' to 'Reset Image and Model' Caches 
-CHANGE: BOM default sort to sort by colour then size, previous default was size only (PLI default sort by size) 
-CHANGE: Change 'Update' tab in preferences dialogue to 'Other'. 
 
LPub3D 1.2.3.443.2 
Features and enhancements 
------------ 
-Fix Insert Text meta command not recognizing \n (new line) characters. 
 
LPub3D 1.2.2.442.3 
Features and enhancements 
------------ 
-Fix: Update fade parts "failed to archive..." error messages 
-Fix: Change fade step color from "Fade Step Setup" menu writes the correct meta command 
 but color does not change when steps generated. 
 
LPub3D 1.2.1.437.2 
 
Features and enhancements 
------------ 
-Fix: PLI/BOM sort routine, sort on 'part colour' part(s) appear out of place relative to 
 part size and colour. 
-CHANGE: BOM default sort to sort by colour then size, previous default was size only (PLI default sort by size) 
 
LPub3D 1.2.0.388.4 
 
Features and enhancements 
------------ 
-Sort PLI/BOM by part size (default), colour and category 
-Improved model navigation - display selected model from model drop-down. Ignored 'meta=IGN' 
 submodels are not displayed even though they are in the drop-down list because they are 
 not assigned a page number. 
-Display LDraw colour code on BOM/PLI tooltip - now showing colour description, colour code and 
 part description. 
-Go To Page navigation combo box - allow page navigation using drop-down box. 
-Show progress bar during display page processing. 
-Text entries can now accommodate quotes using escape character '\' - e.g. This \"Fat\" MOC 
 will display: This "Fat" MOC. Edits must always include the '\' escape character. 
-Fix: When changing the font on added text, the dialogue starts with MS Shell Dlg 2 size 12. 
 The dialogue now starts with display of the actual font parameters being changed. 
-Fix: Change to PLI Times Used attribute on multi-step page now affects only the selected step. 
 when use local option selected. 
-Fix: Change to PLI Text Annotation attribute on multi-step page now affects only the selected step. 
 when use local option selected. 
-Fix: Change to PLI Background attribute on multi-step page now affects only the selected step. 
 when use local option selected. 
-Fix: Change to PLI Border attribute on multi-step page now affects only the selected step. 
 when use local option selected. 
-Fix: Change to Step number attribute on multi-step page now affects only the selected step. PARTIAL - Use 
 local selection still not working. 
 
-CHANGE: Move PLI annotations settings from application preferences to BOM/PLI Setup preferences. 
-CHANGE: LPub3D distribution no longer packed due to reported Win32 incompatability issues. 
 unpacked executable and dependencies are now deposited in installation folder 
 for both x32 and x64 distributions. 
 Windows Content Structure: 
 
LPub3D 1.1.0.370.2 
 
Features and enhancements 
------------ 
-Enable/disable PLI annotations (Preference Dialogue) 
-Edit part title annotations 
-Fix: source URL on about dialogue 
-Fix: .dat subFiles not processed for 3D viewer - causes abnormal end (expected 
 dat files to be treated as part and placed in Official/unofficial parts). 
 Dat subfiles are now treated same as mpd/ldr subfiles. 
 
-CHANGE: isSubmodel check no longer observes meta LDRAW_ORG as Submodel=False 
 
-KNOWN ISSUE: When an image (e.g. logo) is placed bottom left or bottom right 
 right of the page header, dragging the image produces unexpected placement - the same 
 may be true with regards to placement relative to the page footer. 
 WORKAROUND: If you want to reposition by dragging, set the image relative to the Page 
 (any relative position) or bottom centre of the header/ top centre of the footer. 
 
LPub3D 1.0.0.320.2 
 
Features and enhancements 
------------ 
-Integrated 3D Viewer powered by LeoCAD 
-Set ROTSTEP (step rotation) meta using 3D Viewer 
-Fade previous step's parts 
-Use any LDraw colour as fade colour 
-Manage colour parts for complete part fade 
-Unlimited PLI part annotations 
-Split the BOM (divide parts over number of BOM occurrences) 
-Formatted front and back cover pages 
-Automatically generate formatted cover pages 
-POV/L3P high-quality rendered instructions 
-Customizable front and back cover pages 
-Text and picture (e.g. logo) front and back page attributes 
-Customizable content page header and footer 
-LDraw editor line numbers 
-64/32-bit automatic installer 
-Automatic check for updates 
-Qt 4.8.6 
-Bugfixes and robustness improvements 
 
About LPub3D 
------------ 
LPub3D is a WYSIWYG editing application for creating LEGO style digital building instructions. 
It is available for free under the GNU Public License v3 and works on the Windows 
Operating Systems. Portions of LPub3D are based on LPUB© 2007-2009 Kevin Clague, 
LeoCAD© 2015 Leonardo Zide.and additional third party components. 
 
Installation 
------------ 
You can download the latest version of LPub3D from 
https://sourceforge.net/projects/lpub3d 
 
It's recommended that you install the latest drivers for your video card 
since LPub3D uses LeoCAD which uses OpenGL to take advantage of hardware 
acceleration for rendering. 
 
- LPub3D for Windows: 
Download LPub3D to your computer, double click on the 
icon to launch the installer and follow the instructions. 