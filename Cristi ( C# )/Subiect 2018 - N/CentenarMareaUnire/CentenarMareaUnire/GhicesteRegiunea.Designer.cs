namespace CentenarMareaUnire
{
    partial class GhicesteRegiunea
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
            this.btnStart = new System.Windows.Forms.Button();
            this.lbael1 = new System.Windows.Forms.Label();
            this.txtNota = new System.Windows.Forms.TextBox();
            this.btnRaspunde = new System.Windows.Forms.Button();
            this.btnGen = new System.Windows.Forms.Button();
            this.pb = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).BeginInit();
            this.SuspendLayout();
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(671, 50);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(75, 23);
            this.btnStart.TabIndex = 0;
            this.btnStart.Text = "StartJoc";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // lbael1
            // 
            this.lbael1.AutoSize = true;
            this.lbael1.Location = new System.Drawing.Point(622, 121);
            this.lbael1.Name = "lbael1";
            this.lbael1.Size = new System.Drawing.Size(36, 13);
            this.lbael1.TabIndex = 1;
            this.lbael1.Text = "Nota: ";
            // 
            // txtNota
            // 
            this.txtNota.Location = new System.Drawing.Point(664, 118);
            this.txtNota.Name = "txtNota";
            this.txtNota.ReadOnly = true;
            this.txtNota.Size = new System.Drawing.Size(82, 20);
            this.txtNota.TabIndex = 2;
            // 
            // btnRaspunde
            // 
            this.btnRaspunde.Location = new System.Drawing.Point(671, 189);
            this.btnRaspunde.Name = "btnRaspunde";
            this.btnRaspunde.Size = new System.Drawing.Size(75, 23);
            this.btnRaspunde.TabIndex = 3;
            this.btnRaspunde.Text = "Raspunde";
            this.btnRaspunde.UseVisualStyleBackColor = true;
            this.btnRaspunde.Click += new System.EventHandler(this.btnRaspunde_Click);
            // 
            // btnGen
            // 
            this.btnGen.Location = new System.Drawing.Point(664, 230);
            this.btnGen.Name = "btnGen";
            this.btnGen.Size = new System.Drawing.Size(106, 23);
            this.btnGen.TabIndex = 4;
            this.btnGen.Text = "Generare diploma";
            this.btnGen.UseVisualStyleBackColor = true;
            // 
            // pb
            // 
            this.pb.Location = new System.Drawing.Point(12, 12);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(604, 380);
            this.pb.TabIndex = 5;
            this.pb.TabStop = false;
            this.pb.Paint += new System.Windows.Forms.PaintEventHandler(this.pb_Paint);
            // 
            // GhicesteRegiunea
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.pb);
            this.Controls.Add(this.btnGen);
            this.Controls.Add(this.btnRaspunde);
            this.Controls.Add(this.txtNota);
            this.Controls.Add(this.lbael1);
            this.Controls.Add(this.btnStart);
            this.Name = "GhicesteRegiunea";
            this.Text = "GhicesteRegiunea";
            ((System.ComponentModel.ISupportInitialize)(this.pb)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Label lbael1;
        private System.Windows.Forms.TextBox txtNota;
        private System.Windows.Forms.Button btnRaspunde;
        private System.Windows.Forms.Button btnGen;
        private System.Windows.Forms.PictureBox pb;
    }
}