namespace SniperGame
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.topPipeBody = new System.Windows.Forms.PictureBox();
            this.topPipeHead = new System.Windows.Forms.PictureBox();
            this.pbJucator = new System.Windows.Forms.PictureBox();
            this.BotPipeHead = new System.Windows.Forms.PictureBox();
            this.BotPipeBody = new System.Windows.Forms.PictureBox();
            this.lblScor = new System.Windows.Forms.Label();
            this.GameOver = new System.Windows.Forms.Label();
            this.lblFinal = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.topPipeBody)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.topPipeHead)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbJucator)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BotPipeHead)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BotPipeBody)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.Lime;
            this.pictureBox1.Location = new System.Drawing.Point(-9, 419);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(826, 50);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // topPipeBody
            // 
            this.topPipeBody.BackColor = System.Drawing.Color.Lime;
            this.topPipeBody.Location = new System.Drawing.Point(358, -1);
            this.topPipeBody.Name = "topPipeBody";
            this.topPipeBody.Size = new System.Drawing.Size(86, 124);
            this.topPipeBody.TabIndex = 1;
            this.topPipeBody.TabStop = false;
            this.topPipeBody.Tag = "top";
            // 
            // topPipeHead
            // 
            this.topPipeHead.BackColor = System.Drawing.Color.Lime;
            this.topPipeHead.Location = new System.Drawing.Point(347, 105);
            this.topPipeHead.Name = "topPipeHead";
            this.topPipeHead.Size = new System.Drawing.Size(110, 31);
            this.topPipeHead.TabIndex = 2;
            this.topPipeHead.TabStop = false;
            this.topPipeHead.Tag = "top";
            // 
            // pbJucator
            // 
            this.pbJucator.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.pbJucator.Image = ((System.Drawing.Image)(resources.GetObject("pbJucator.Image")));
            this.pbJucator.Location = new System.Drawing.Point(40, 146);
            this.pbJucator.Name = "pbJucator";
            this.pbJucator.Size = new System.Drawing.Size(66, 50);
            this.pbJucator.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbJucator.TabIndex = 3;
            this.pbJucator.TabStop = false;
            this.pbJucator.Tag = "jucator";
            // 
            // BotPipeHead
            // 
            this.BotPipeHead.BackColor = System.Drawing.Color.Lime;
            this.BotPipeHead.Location = new System.Drawing.Point(689, 284);
            this.BotPipeHead.Name = "BotPipeHead";
            this.BotPipeHead.Size = new System.Drawing.Size(110, 31);
            this.BotPipeHead.TabIndex = 5;
            this.BotPipeHead.TabStop = false;
            this.BotPipeHead.Tag = "bot";
            // 
            // BotPipeBody
            // 
            this.BotPipeBody.BackColor = System.Drawing.Color.Lime;
            this.BotPipeBody.Location = new System.Drawing.Point(702, 302);
            this.BotPipeBody.Name = "BotPipeBody";
            this.BotPipeBody.Size = new System.Drawing.Size(86, 124);
            this.BotPipeBody.TabIndex = 4;
            this.BotPipeBody.TabStop = false;
            this.BotPipeBody.Tag = "bot";
            // 
            // lblScor
            // 
            this.lblScor.AutoSize = true;
            this.lblScor.Location = new System.Drawing.Point(255, 169);
            this.lblScor.Name = "lblScor";
            this.lblScor.Size = new System.Drawing.Size(35, 13);
            this.lblScor.TabIndex = 6;
            this.lblScor.Text = "label1";
            // 
            // GameOver
            // 
            this.GameOver.AutoSize = true;
            this.GameOver.Location = new System.Drawing.Point(255, 201);
            this.GameOver.Name = "GameOver";
            this.GameOver.Size = new System.Drawing.Size(58, 13);
            this.GameOver.TabIndex = 7;
            this.GameOver.Text = "GameOver";
            this.GameOver.Visible = false;
            // 
            // lblFinal
            // 
            this.lblFinal.AutoSize = true;
            this.lblFinal.Location = new System.Drawing.Point(255, 229);
            this.lblFinal.Name = "lblFinal";
            this.lblFinal.Size = new System.Drawing.Size(35, 13);
            this.lblFinal.TabIndex = 8;
            this.lblFinal.Text = "label3";
            this.lblFinal.Visible = false;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(255, 256);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(112, 13);
            this.label4.TabIndex = 9;
            this.label4.Text = "GameDesigned by Me";
            this.label4.Visible = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.lblFinal);
            this.Controls.Add(this.GameOver);
            this.Controls.Add(this.lblScor);
            this.Controls.Add(this.BotPipeHead);
            this.Controls.Add(this.BotPipeBody);
            this.Controls.Add(this.pbJucator);
            this.Controls.Add(this.topPipeHead);
            this.Controls.Add(this.topPipeBody);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyUp);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.topPipeBody)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.topPipeHead)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbJucator)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BotPipeHead)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BotPipeBody)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox topPipeBody;
        private System.Windows.Forms.PictureBox topPipeHead;
        private System.Windows.Forms.PictureBox pbJucator;
        private System.Windows.Forms.PictureBox BotPipeHead;
        private System.Windows.Forms.PictureBox BotPipeBody;
        private System.Windows.Forms.Label lblScor;
        private System.Windows.Forms.Label GameOver;
        private System.Windows.Forms.Label lblFinal;
        private System.Windows.Forms.Label label4;
    }
}

