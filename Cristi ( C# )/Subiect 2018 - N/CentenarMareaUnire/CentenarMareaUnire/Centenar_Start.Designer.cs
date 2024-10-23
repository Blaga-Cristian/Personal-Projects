namespace CentenarMareaUnire
{
    partial class Centenar_Start
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
            this.btnLogare = new System.Windows.Forms.Button();
            this.btnLectie = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnLogare
            // 
            this.btnLogare.Location = new System.Drawing.Point(527, 112);
            this.btnLogare.Name = "btnLogare";
            this.btnLogare.Size = new System.Drawing.Size(75, 23);
            this.btnLogare.TabIndex = 0;
            this.btnLogare.Text = "Logare";
            this.btnLogare.UseVisualStyleBackColor = true;
            this.btnLogare.Click += new System.EventHandler(this.btnLogare_Click);
            // 
            // btnLectie
            // 
            this.btnLectie.Location = new System.Drawing.Point(134, 112);
            this.btnLectie.Name = "btnLectie";
            this.btnLectie.Size = new System.Drawing.Size(75, 23);
            this.btnLectie.TabIndex = 1;
            this.btnLectie.Text = "Vizualizare Lectii";
            this.btnLectie.UseVisualStyleBackColor = true;
            this.btnLectie.Click += new System.EventHandler(this.btnLectie_Click);
            // 
            // Centenar_Start
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnLectie);
            this.Controls.Add(this.btnLogare);
            this.Name = "Centenar_Start";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Centenar_Start";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnLogare;
        private System.Windows.Forms.Button btnLectie;
    }
}

