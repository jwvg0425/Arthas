namespace ArthasStudio
{
	partial class mainForm
	{
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		/// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form 디자이너에서 생성한 코드

		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다.
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Sprite");
			System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("Animations");
			System.Windows.Forms.TreeNode treeNode3 = new System.Windows.Forms.TreeNode("Sounds");
			System.Windows.Forms.TreeNode treeNode4 = new System.Windows.Forms.TreeNode("Strings");
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(mainForm));
			this.spriteMenuStrip = new System.Windows.Forms.ContextMenuStrip(this.components);
			this.newSpriteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.newFolderToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
			this.copyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.sortingToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
			this.changeNameToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.propertiesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.menuStrip1 = new System.Windows.Forms.MenuStrip();
			this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.newFileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.saveFileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.infoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.mainTreeView = new System.Windows.Forms.TreeView();
			this.imageList1 = new System.Windows.Forms.ImageList(this.components);
			this.splitter1 = new System.Windows.Forms.Splitter();
			this.mainStatusStrip = new System.Windows.Forms.StatusStrip();
			this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
			this.spriteMenuStrip.SuspendLayout();
			this.menuStrip1.SuspendLayout();
			this.mainStatusStrip.SuspendLayout();
			this.SuspendLayout();
			// 
			// spriteMenuStrip
			// 
			this.spriteMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newSpriteToolStripMenuItem,
            this.newFolderToolStripMenuItem,
            this.toolStripSeparator1,
            this.copyToolStripMenuItem,
            this.sortingToolStripMenuItem,
            this.toolStripSeparator3,
            this.changeNameToolStripMenuItem,
            this.propertiesToolStripMenuItem});
			this.spriteMenuStrip.Name = "spriteMenuStrip";
			this.spriteMenuStrip.Size = new System.Drawing.Size(153, 170);
			// 
			// newSpriteToolStripMenuItem
			// 
			this.newSpriteToolStripMenuItem.Name = "newSpriteToolStripMenuItem";
			this.newSpriteToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
			this.newSpriteToolStripMenuItem.Text = "NewSprite";
			// 
			// newFolderToolStripMenuItem
			// 
			this.newFolderToolStripMenuItem.Name = "newFolderToolStripMenuItem";
			this.newFolderToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
			this.newFolderToolStripMenuItem.Text = "NewFolder";
			this.newFolderToolStripMenuItem.Click += new System.EventHandler(this.newFolderToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this.toolStripSeparator1.Name = "toolStripSeparator1";
			this.toolStripSeparator1.Size = new System.Drawing.Size(149, 6);
			// 
			// copyToolStripMenuItem
			// 
			this.copyToolStripMenuItem.Enabled = false;
			this.copyToolStripMenuItem.Name = "copyToolStripMenuItem";
			this.copyToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
			this.copyToolStripMenuItem.Text = "Copy";
			// 
			// sortingToolStripMenuItem
			// 
			this.sortingToolStripMenuItem.Name = "sortingToolStripMenuItem";
			this.sortingToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
			this.sortingToolStripMenuItem.Text = "Sort";
			// 
			// toolStripSeparator3
			// 
			this.toolStripSeparator3.Name = "toolStripSeparator3";
			this.toolStripSeparator3.Size = new System.Drawing.Size(149, 6);
			// 
			// changeNameToolStripMenuItem
			// 
			this.changeNameToolStripMenuItem.Enabled = false;
			this.changeNameToolStripMenuItem.Name = "changeNameToolStripMenuItem";
			this.changeNameToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
			this.changeNameToolStripMenuItem.Text = "ChangeName";
			// 
			// propertiesToolStripMenuItem
			// 
			this.propertiesToolStripMenuItem.Enabled = false;
			this.propertiesToolStripMenuItem.Name = "propertiesToolStripMenuItem";
			this.propertiesToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
			this.propertiesToolStripMenuItem.Text = "Properties";
			// 
			// menuStrip1
			// 
			this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.viewToolStripMenuItem,
            this.infoToolStripMenuItem});
			this.menuStrip1.Location = new System.Drawing.Point(0, 0);
			this.menuStrip1.Name = "menuStrip1";
			this.menuStrip1.Size = new System.Drawing.Size(686, 24);
			this.menuStrip1.TabIndex = 1;
			this.menuStrip1.Text = "mainMenuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newFileToolStripMenuItem,
            this.saveFileToolStripMenuItem});
			this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
			this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
			this.fileToolStripMenuItem.Text = "File";
			// 
			// newFileToolStripMenuItem
			// 
			this.newFileToolStripMenuItem.Name = "newFileToolStripMenuItem";
			this.newFileToolStripMenuItem.Size = new System.Drawing.Size(121, 22);
			this.newFileToolStripMenuItem.Text = "New File";
			// 
			// saveFileToolStripMenuItem
			// 
			this.saveFileToolStripMenuItem.Name = "saveFileToolStripMenuItem";
			this.saveFileToolStripMenuItem.Size = new System.Drawing.Size(121, 22);
			this.saveFileToolStripMenuItem.Text = "Save File";
			// 
			// editToolStripMenuItem
			// 
			this.editToolStripMenuItem.Name = "editToolStripMenuItem";
			this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
			this.editToolStripMenuItem.Text = "Edit";
			// 
			// viewToolStripMenuItem
			// 
			this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
			this.viewToolStripMenuItem.Size = new System.Drawing.Size(45, 20);
			this.viewToolStripMenuItem.Text = "View";
			// 
			// infoToolStripMenuItem
			// 
			this.infoToolStripMenuItem.Name = "infoToolStripMenuItem";
			this.infoToolStripMenuItem.Size = new System.Drawing.Size(40, 20);
			this.infoToolStripMenuItem.Text = "Info";
			// 
			// mainTreeView
			// 
			this.mainTreeView.Dock = System.Windows.Forms.DockStyle.Left;
			this.mainTreeView.ImageIndex = 0;
			this.mainTreeView.ImageList = this.imageList1;
			this.mainTreeView.Location = new System.Drawing.Point(0, 24);
			this.mainTreeView.Name = "mainTreeView";
			treeNode1.ContextMenuStrip = this.spriteMenuStrip;
			treeNode1.Name = "spriteNodes";
			treeNode1.Text = "Sprite";
			treeNode2.Name = "animationNodes";
			treeNode2.Text = "Animations";
			treeNode3.Name = "soundNodes";
			treeNode3.Text = "Sounds";
			treeNode4.Name = "stringNodes";
			treeNode4.Text = "Strings";
			this.mainTreeView.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode1,
            treeNode2,
            treeNode3,
            treeNode4});
			this.mainTreeView.SelectedImageIndex = 1;
			this.mainTreeView.Size = new System.Drawing.Size(185, 412);
			this.mainTreeView.TabIndex = 2;
			// 
			// imageList1
			// 
			this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
			this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
			this.imageList1.Images.SetKeyName(0, "image_set_001.bmp");
			this.imageList1.Images.SetKeyName(1, "image_set_002.bmp");
			this.imageList1.Images.SetKeyName(2, "image_set_003.bmp");
			this.imageList1.Images.SetKeyName(3, "image_set_004.bmp");
			this.imageList1.Images.SetKeyName(4, "image_set_005.bmp");
			this.imageList1.Images.SetKeyName(5, "image_set_006.bmp");
			this.imageList1.Images.SetKeyName(6, "image_set_007.bmp");
			this.imageList1.Images.SetKeyName(7, "image_set_008.bmp");
			this.imageList1.Images.SetKeyName(8, "image_set_009.bmp");
			this.imageList1.Images.SetKeyName(9, "image_set_010.bmp");
			this.imageList1.Images.SetKeyName(10, "image_set_011.bmp");
			this.imageList1.Images.SetKeyName(11, "image_set_012.bmp");
			this.imageList1.Images.SetKeyName(12, "image_set_013.bmp");
			this.imageList1.Images.SetKeyName(13, "image_set_014.bmp");
			this.imageList1.Images.SetKeyName(14, "image_set_015.bmp");
			this.imageList1.Images.SetKeyName(15, "image_set_016.bmp");
			this.imageList1.Images.SetKeyName(16, "image_set_017.bmp");
			// 
			// splitter1
			// 
			this.splitter1.Location = new System.Drawing.Point(185, 24);
			this.splitter1.Name = "splitter1";
			this.splitter1.Size = new System.Drawing.Size(3, 412);
			this.splitter1.TabIndex = 3;
			this.splitter1.TabStop = false;
			// 
			// mainStatusStrip
			// 
			this.mainStatusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1});
			this.mainStatusStrip.Location = new System.Drawing.Point(188, 414);
			this.mainStatusStrip.Name = "mainStatusStrip";
			this.mainStatusStrip.Size = new System.Drawing.Size(498, 22);
			this.mainStatusStrip.TabIndex = 4;
			this.mainStatusStrip.Text = "statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
			this.toolStripStatusLabel1.Size = new System.Drawing.Size(46, 17);
			this.toolStripStatusLabel1.Text = "Label 1";
			// 
			// mainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(686, 436);
			this.Controls.Add(this.mainStatusStrip);
			this.Controls.Add(this.splitter1);
			this.Controls.Add(this.mainTreeView);
			this.Controls.Add(this.menuStrip1);
			this.IsMdiContainer = true;
			this.MainMenuStrip = this.menuStrip1;
			this.Name = "mainForm";
			this.Text = "ArthuStudio alpha";
			this.spriteMenuStrip.ResumeLayout(false);
			this.menuStrip1.ResumeLayout(false);
			this.menuStrip1.PerformLayout();
			this.mainStatusStrip.ResumeLayout(false);
			this.mainStatusStrip.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.MenuStrip menuStrip1;
		private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem newFileToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem saveFileToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem infoToolStripMenuItem;
		private System.Windows.Forms.TreeView mainTreeView;
		private System.Windows.Forms.Splitter splitter1;
		private System.Windows.Forms.StatusStrip mainStatusStrip;
		private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
		private System.Windows.Forms.ImageList imageList1;
		private System.Windows.Forms.ContextMenuStrip spriteMenuStrip;
		private System.Windows.Forms.ToolStripMenuItem newSpriteToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem newFolderToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
		private System.Windows.Forms.ToolStripMenuItem copyToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem sortingToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
		private System.Windows.Forms.ToolStripMenuItem changeNameToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem propertiesToolStripMenuItem;
	}
}

