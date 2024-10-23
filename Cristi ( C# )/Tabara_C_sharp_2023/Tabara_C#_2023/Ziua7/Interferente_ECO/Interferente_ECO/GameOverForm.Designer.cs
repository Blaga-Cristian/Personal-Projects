
namespace Interferente_ECO
{
    partial class GameOverForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(GameOverForm));
            this.lblStop = new System.Windows.Forms.Label();
            this.btnRestart = new System.Windows.Forms.Button();
            this.btnExitAppp = new System.Windows.Forms.Button();
            this.lblQuestion = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblStop
            // 
            this.lblStop.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblStop.ForeColor = System.Drawing.Color.Red;
            this.lblStop.Location = new System.Drawing.Point(45, 34);
            this.lblStop.Name = "lblStop";
            this.lblStop.Size = new System.Drawing.Size(468, 36);
            this.lblStop.TabIndex = 0;
            this.lblStop.Text = "Jocul s-a terminat. Ai trecut peste o meduză!";
            this.lblStop.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btnRestart
            // 
            this.btnRestart.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRestart.ForeColor = System.Drawing.Color.Red;
            this.btnRestart.Location = new System.Drawing.Point(45, 175);
            this.btnRestart.Name = "btnRestart";
            this.btnRestart.Size = new System.Drawing.Size(219, 58);
            this.btnRestart.TabIndex = 1;
            this.btnRestart.Text = "Reincep jocul";
            this.btnRestart.UseVisualStyleBackColor = true;
            this.btnRestart.Click += new System.EventHandler(this.btnRestart_Click);
            // 
            // btnExitAppp
            // 
            this.btnExitAppp.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnExitAppp.ForeColor = System.Drawing.Color.Red;
            this.btnExitAppp.Location = new System.Drawing.Point(287, 175);
            this.btnExitAppp.Name = "btnExitAppp";
            this.btnExitAppp.Size = new System.Drawing.Size(226, 58);
            this.btnExitAppp.TabIndex = 2;
            this.btnExitAppp.Text = "Termin jocul";
            this.btnExitAppp.UseVisualStyleBackColor = true;
            this.btnExitAppp.Click += new System.EventHandler(this.btnExitAppp_Click);
            // 
            // lblQuestion
            // 
            this.lblQuestion.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblQuestion.ForeColor = System.Drawing.Color.Red;
            this.lblQuestion.Location = new System.Drawing.Point(42, 115);
            this.lblQuestion.Name = "lblQuestion";
            this.lblQuestion.Size = new System.Drawing.Size(468, 36);
            this.lblQuestion.TabIndex = 3;
            this.lblQuestion.Text = "Reîcepi sau vrei să temini  ?";
            this.lblQuestion.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // GameOverForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(553, 267);
            this.Controls.Add(this.lblQuestion);
            this.Controls.Add(this.btnExitAppp);
            this.Controls.Add(this.btnRestart);
            this.Controls.Add(this.lblStop);
            this.Name = "GameOverForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Joc Oprit";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label lblStop;
        private System.Windows.Forms.Button btnRestart;
        private System.Windows.Forms.Button btnExitAppp;
        private System.Windows.Forms.Label lblQuestion;
    }
}