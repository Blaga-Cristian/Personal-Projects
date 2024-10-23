namespace Programmers
{
    partial class ProgrammersForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.dgw = new System.Windows.Forms.DataGridView();
            this.cmbNames = new System.Windows.Forms.ComboBox();
            this.lblPosition = new System.Windows.Forms.Label();
            this.lstSalary = new System.Windows.Forms.ListBox();
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).BeginInit();
            this.SuspendLayout();
            // 
            // dgw
            // 
            this.dgw.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgw.Location = new System.Drawing.Point(12, 23);
            this.dgw.Name = "dgw";
            this.dgw.Size = new System.Drawing.Size(525, 201);
            this.dgw.TabIndex = 0;
            // 
            // cmbNames
            // 
            this.cmbNames.FormattingEnabled = true;
            this.cmbNames.Location = new System.Drawing.Point(13, 249);
            this.cmbNames.Name = "cmbNames";
            this.cmbNames.Size = new System.Drawing.Size(121, 21);
            this.cmbNames.TabIndex = 1;
            this.cmbNames.SelectedIndexChanged += new System.EventHandler(this.cmbNames_SelectedIndexChanged);
            // 
            // lblPosition
            // 
            this.lblPosition.AutoSize = true;
            this.lblPosition.Location = new System.Drawing.Point(12, 282);
            this.lblPosition.Name = "lblPosition";
            this.lblPosition.Size = new System.Drawing.Size(41, 13);
            this.lblPosition.TabIndex = 2;
            this.lblPosition.Text = "Pozitia:";
            // 
            // lstSalary
            // 
            this.lstSalary.FormattingEnabled = true;
            this.lstSalary.Location = new System.Drawing.Point(187, 249);
            this.lstSalary.Name = "lstSalary";
            this.lstSalary.Size = new System.Drawing.Size(120, 186);
            this.lstSalary.TabIndex = 3;
            // 
            // ProgrammersForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(564, 460);
            this.Controls.Add(this.lstSalary);
            this.Controls.Add(this.lblPosition);
            this.Controls.Add(this.cmbNames);
            this.Controls.Add(this.dgw);
            this.Name = "ProgrammersForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.ProgrammersForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dgw;
        private System.Windows.Forms.ComboBox cmbNames;
        private System.Windows.Forms.Label lblPosition;
        private System.Windows.Forms.ListBox lstSalary;
    }
}

