namespace Fractal
{
    partial class Form1
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
            this.btnStartFractal = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnStartFractal
            // 
            this.btnStartFractal.Location = new System.Drawing.Point(27, 21);
            this.btnStartFractal.Name = "btnStartFractal";
            this.btnStartFractal.Size = new System.Drawing.Size(156, 41);
            this.btnStartFractal.TabIndex = 0;
            this.btnStartFractal.Text = "Start Fractal";
            this.btnStartFractal.UseVisualStyleBackColor = true;
            this.btnStartFractal.Click += new System.EventHandler(this.btnStartFractal_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnStartFractal);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnStartFractal;
    }
}

