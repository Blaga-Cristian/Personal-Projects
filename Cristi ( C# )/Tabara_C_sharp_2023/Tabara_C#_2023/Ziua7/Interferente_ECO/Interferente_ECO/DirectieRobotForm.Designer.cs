
namespace Interferente_ECO
{
    partial class DirectieRobotForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DirectieRobotForm));
            this.lblChooseDirecrtion = new System.Windows.Forms.Label();
            this.btnSus = new System.Windows.Forms.Button();
            this.btnDreapta = new System.Windows.Forms.Button();
            this.btnJos = new System.Windows.Forms.Button();
            this.btnStanga = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblChooseDirecrtion
            // 
            this.lblChooseDirecrtion.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblChooseDirecrtion.ForeColor = System.Drawing.Color.White;
            this.lblChooseDirecrtion.Location = new System.Drawing.Point(52, 27);
            this.lblChooseDirecrtion.Name = "lblChooseDirecrtion";
            this.lblChooseDirecrtion.Size = new System.Drawing.Size(428, 43);
            this.lblChooseDirecrtion.TabIndex = 0;
            this.lblChooseDirecrtion.Text = "Alegeți direcția de deplasare a robotului";
            this.lblChooseDirecrtion.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btnSus
            // 
            this.btnSus.BackColor = System.Drawing.Color.DarkRed;
            this.btnSus.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSus.ForeColor = System.Drawing.Color.White;
            this.btnSus.Location = new System.Drawing.Point(211, 80);
            this.btnSus.Name = "btnSus";
            this.btnSus.Size = new System.Drawing.Size(78, 65);
            this.btnSus.TabIndex = 1;
            this.btnSus.Text = "Sus";
            this.btnSus.UseVisualStyleBackColor = false;
            this.btnSus.Click += new System.EventHandler(this.btnSus_Click);
            // 
            // btnDreapta
            // 
            this.btnDreapta.BackColor = System.Drawing.Color.DarkRed;
            this.btnDreapta.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnDreapta.ForeColor = System.Drawing.Color.White;
            this.btnDreapta.Location = new System.Drawing.Point(286, 141);
            this.btnDreapta.Name = "btnDreapta";
            this.btnDreapta.Size = new System.Drawing.Size(78, 65);
            this.btnDreapta.TabIndex = 2;
            this.btnDreapta.Text = "Dreapta";
            this.btnDreapta.UseVisualStyleBackColor = false;
            this.btnDreapta.Click += new System.EventHandler(this.btnDreapta_Click);
            // 
            // btnJos
            // 
            this.btnJos.BackColor = System.Drawing.Color.DarkRed;
            this.btnJos.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnJos.ForeColor = System.Drawing.Color.White;
            this.btnJos.Location = new System.Drawing.Point(212, 203);
            this.btnJos.Name = "btnJos";
            this.btnJos.Size = new System.Drawing.Size(78, 65);
            this.btnJos.TabIndex = 3;
            this.btnJos.Text = "Jos";
            this.btnJos.UseVisualStyleBackColor = false;
            this.btnJos.Click += new System.EventHandler(this.btnJos_Click);
            // 
            // btnStanga
            // 
            this.btnStanga.BackColor = System.Drawing.Color.DarkRed;
            this.btnStanga.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStanga.ForeColor = System.Drawing.Color.White;
            this.btnStanga.Location = new System.Drawing.Point(138, 141);
            this.btnStanga.Name = "btnStanga";
            this.btnStanga.Size = new System.Drawing.Size(78, 65);
            this.btnStanga.TabIndex = 4;
            this.btnStanga.Text = "Stanga";
            this.btnStanga.UseVisualStyleBackColor = false;
            this.btnStanga.Click += new System.EventHandler(this.btnStanga_Click);
            // 
            // DirectieRobotForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(519, 281);
            this.Controls.Add(this.btnStanga);
            this.Controls.Add(this.btnJos);
            this.Controls.Add(this.btnDreapta);
            this.Controls.Add(this.btnSus);
            this.Controls.Add(this.lblChooseDirecrtion);
            this.Name = "DirectieRobotForm";
            this.Text = "ADirectia Robotului";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label lblChooseDirecrtion;
        private System.Windows.Forms.Button btnSus;
        private System.Windows.Forms.Button btnDreapta;
        private System.Windows.Forms.Button btnJos;
        private System.Windows.Forms.Button btnStanga;
    }
}