namespace Subiect_2023___J__redo_redo_2024_
{
    partial class Ghiceste
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
            this.pbFloare = new System.Windows.Forms.PictureBox();
            this.lblScor = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pbFloare)).BeginInit();
            this.SuspendLayout();
            // 
            // pbFloare
            // 
            this.pbFloare.Location = new System.Drawing.Point(689, 27);
            this.pbFloare.Name = "pbFloare";
            this.pbFloare.Size = new System.Drawing.Size(323, 480);
            this.pbFloare.TabIndex = 0;
            this.pbFloare.TabStop = false;
            // 
            // lblScor
            // 
            this.lblScor.AutoSize = true;
            this.lblScor.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lblScor.Location = new System.Drawing.Point(12, 36);
            this.lblScor.Name = "lblScor";
            this.lblScor.Size = new System.Drawing.Size(92, 31);
            this.lblScor.TabIndex = 1;
            this.lblScor.Text = "label1";
            // 
            // Ghiceste
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1038, 536);
            this.Controls.Add(this.lblScor);
            this.Controls.Add(this.pbFloare);
            this.Name = "Ghiceste";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Ghiceste";
            ((System.ComponentModel.ISupportInitialize)(this.pbFloare)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pbFloare;
        private System.Windows.Forms.Label lblScor;
    }
}