namespace Calatorie
{
    partial class Meniu
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
            this.btnAdministrare = new System.Windows.Forms.Button();
            this.btnTuristi = new System.Windows.Forms.Button();
            this.btnIesire = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnAdministrare
            // 
            this.btnAdministrare.Location = new System.Drawing.Point(35, 21);
            this.btnAdministrare.Name = "btnAdministrare";
            this.btnAdministrare.Size = new System.Drawing.Size(119, 32);
            this.btnAdministrare.TabIndex = 0;
            this.btnAdministrare.Text = "Administrare";
            this.btnAdministrare.UseVisualStyleBackColor = true;
            this.btnAdministrare.Click += new System.EventHandler(this.btnAdministrare_Click);
            // 
            // btnTuristi
            // 
            this.btnTuristi.Location = new System.Drawing.Point(35, 59);
            this.btnTuristi.Name = "btnTuristi";
            this.btnTuristi.Size = new System.Drawing.Size(119, 32);
            this.btnTuristi.TabIndex = 1;
            this.btnTuristi.Text = "Turisti";
            this.btnTuristi.UseVisualStyleBackColor = true;
            this.btnTuristi.Click += new System.EventHandler(this.btnTuristi_Click);
            // 
            // btnIesire
            // 
            this.btnIesire.Location = new System.Drawing.Point(35, 97);
            this.btnIesire.Name = "btnIesire";
            this.btnIesire.Size = new System.Drawing.Size(119, 32);
            this.btnIesire.TabIndex = 2;
            this.btnIesire.Text = "Iesire";
            this.btnIesire.UseVisualStyleBackColor = true;
            this.btnIesire.Click += new System.EventHandler(this.btnIesire_Click);
            // 
            // Meniu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(183, 156);
            this.Controls.Add(this.btnIesire);
            this.Controls.Add(this.btnTuristi);
            this.Controls.Add(this.btnAdministrare);
            this.Name = "Meniu";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Meniu";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnAdministrare;
        private System.Windows.Forms.Button btnTuristi;
        private System.Windows.Forms.Button btnIesire;
    }
}