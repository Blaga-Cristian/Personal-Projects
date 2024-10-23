namespace AplicatieFreeBook
{
    partial class AfiseazaCarte
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
            this.wbCarte = new System.Windows.Forms.WebBrowser();
            this.SuspendLayout();
            // 
            // wbCarte
            // 
            this.wbCarte.Dock = System.Windows.Forms.DockStyle.Fill;
            this.wbCarte.Location = new System.Drawing.Point(0, 0);
            this.wbCarte.MinimumSize = new System.Drawing.Size(20, 20);
            this.wbCarte.Name = "wbCarte";
            this.wbCarte.Size = new System.Drawing.Size(800, 450);
            this.wbCarte.TabIndex = 0;
            // 
            // AfiseazaCarte
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.wbCarte);
            this.Name = "AfiseazaCarte";
            this.Text = "AfiseazaCarte";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.WebBrowser wbCarte;
    }
}