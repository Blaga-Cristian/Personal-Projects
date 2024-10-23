namespace JocEducativ
{
    partial class GhicesteCuvant
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
            this.lblPunctaj = new System.Windows.Forms.Label();
            this.pb = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).BeginInit();
            this.SuspendLayout();
            // 
            // lblPunctaj
            // 
            this.lblPunctaj.AutoSize = true;
            this.lblPunctaj.Location = new System.Drawing.Point(34, 29);
            this.lblPunctaj.Name = "lblPunctaj";
            this.lblPunctaj.Size = new System.Drawing.Size(35, 13);
            this.lblPunctaj.TabIndex = 1;
            this.lblPunctaj.Text = "label2";
            // 
            // pb
            // 
            this.pb.Location = new System.Drawing.Point(497, 29);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(261, 319);
            this.pb.TabIndex = 2;
            this.pb.TabStop = false;
            // 
            // GhicesteCuvant
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.pb);
            this.Controls.Add(this.lblPunctaj);
            this.Name = "GhicesteCuvant";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "GhicesteCuvant";
            ((System.ComponentModel.ISupportInitialize)(this.pb)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblPunctaj;
        private System.Windows.Forms.PictureBox pb;
    }
}