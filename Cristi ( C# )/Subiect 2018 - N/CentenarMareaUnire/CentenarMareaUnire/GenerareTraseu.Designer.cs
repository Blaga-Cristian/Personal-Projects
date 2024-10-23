namespace CentenarMareaUnire
{
    partial class GenerareTraseu
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
            this.cmb = new System.Windows.Forms.ComboBox();
            this.bntGen = new System.Windows.Forms.Button();
            this.pb = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).BeginInit();
            this.SuspendLayout();
            // 
            // cmb
            // 
            this.cmb.FormattingEnabled = true;
            this.cmb.Location = new System.Drawing.Point(668, 31);
            this.cmb.Name = "cmb";
            this.cmb.Size = new System.Drawing.Size(121, 21);
            this.cmb.TabIndex = 1;
            // 
            // bntGen
            // 
            this.bntGen.Location = new System.Drawing.Point(678, 58);
            this.bntGen.Name = "bntGen";
            this.bntGen.Size = new System.Drawing.Size(100, 23);
            this.bntGen.TabIndex = 2;
            this.bntGen.Text = "Generare traseu";
            this.bntGen.UseVisualStyleBackColor = true;
            this.bntGen.Click += new System.EventHandler(this.bntGen_Click);
            // 
            // pb
            // 
            this.pb.Location = new System.Drawing.Point(-1, 2);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(663, 455);
            this.pb.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pb.TabIndex = 3;
            this.pb.TabStop = false;
            this.pb.Paint += new System.Windows.Forms.PaintEventHandler(this.pb_Paint);
            // 
            // GenerareTraseu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.pb);
            this.Controls.Add(this.bntGen);
            this.Controls.Add(this.cmb);
            this.Name = "GenerareTraseu";
            this.Text = "GenerareTraseu";
            ((System.ComponentModel.ISupportInitialize)(this.pb)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.ComboBox cmb;
        private System.Windows.Forms.Button bntGen;
        private System.Windows.Forms.PictureBox pb;
    }
}