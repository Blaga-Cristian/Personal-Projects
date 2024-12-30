package org.example.pycharmplugin

import com.intellij.openapi.actionSystem.ActionUpdateThread
import com.intellij.openapi.actionSystem.AnAction
import com.intellij.openapi.actionSystem.AnActionEvent
import com.intellij.openapi.actionSystem.CommonDataKeys
import com.intellij.openapi.editor.Editor
import com.intellij.openapi.project.Project
import com.intellij.openapi.ui.Messages
import java.io.File
import java.io.IOException
import java.nio.file.Files
import java.nio.file.StandardCopyOption

class MyTextSelectionAction : AnAction() {
    override fun getActionUpdateThread(): ActionUpdateThread {
        return ActionUpdateThread.EDT
    }

    override fun actionPerformed(e: AnActionEvent) {
        // Get the current project
        val project: Project? = e.project

        // Get the editor instance
        val editor: Editor? = e.getData(CommonDataKeys.EDITOR)

        // Check if an editor is open
        if (editor != null) {
            // Get the selection model
            val selectionModel = editor.selectionModel
            val selectedText = selectionModel.selectedText

            if (!selectedText.isNullOrEmpty()) {
                // Show the selected text in a dialog
                Messages.showMessageDialog(
                    project,
                    "Selected text: $selectedText",
                    "Selection Info",
                    Messages.getInformationIcon()
                )

                runPythonScript(project, selectedText)
            } else {
                // Notify that no text is selected, though it shouldn't show up if no text is selected
                Messages.showMessageDialog(
                    project,
                    "No text selected.",
                    "Selection Info",
                    Messages.getInformationIcon()
                )
            }
        }
    }

    override fun update(e: AnActionEvent) {
        // Enable the action only if text is selected
        val editor: Editor? = e.getData(CommonDataKeys.EDITOR)
        val hasSelection = editor?.selectionModel?.hasSelection() ?: false
        e.presentation.isEnabledAndVisible = editor != null && hasSelection
    }

    private fun runPythonScript(project: Project?, text : String) = try {
        // Get the url of the script file from the resource folder
        val scriptUrl = MyTextSelectionAction::class.java.getResource("/python_script.py")

        //Create a temporary file from which the script code will be run
        val tempScriptFile = File.createTempFile("python_script", ".py")
        tempScriptFile.deleteOnExit()

        //Copy the contents of the resource script file to the temporary file
        val inputStream = scriptUrl?.openStream() ?: throw Exception("Failed to open script file")
        Files.copy(inputStream, tempScriptFile.toPath(), StandardCopyOption.REPLACE_EXISTING)
        inputStream.close()

        //Use ProcessBuilder to run the script from the temporary file
        val processBuilder = ProcessBuilder("py", tempScriptFile.absolutePath, text)
        processBuilder.redirectErrorStream(true)
        val process = processBuilder.start()

        //Get output and error streams
        val output = process.inputStream.bufferedReader().use { it.readText() }
        val error = process.errorStream.bufferedReader().use { it.readText() }

        if (error.isNotEmpty()) {
            //An error has occurred in executing the script
            Messages.showMessageDialog(
                project,
                "Error in Python script:\n$error",
                "Python Script Error",
                Messages.getErrorIcon()
            )
        } else {
            //Show the output of the script, should be a sequence of numbers
            Messages.showMessageDialog(
                project,
                "Python script output:\n$output",
                "Python Script Output",
                Messages.getInformationIcon()
            )
        }
    } catch (e: IOException) {
        //The python script could not be run
        Messages.showMessageDialog(
            project,
            "Failed to run python script: ${e.message}",
            "Error",
            Messages.getErrorIcon()
        )
    }
}