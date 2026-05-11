# 计算机软件著作权登记申请 LaTeX 模板

本项目是用于计算机软件著作权登记申请材料编写的 LaTeX 模板，适合生成软件设计说明书、使用说明书等中文 PDF 文档。模板基于 `ctexart`、`xeCJK` 等中文排版组件，已配置 A4 页面、中文字体、页眉页脚、封面、修订记录、目录和正文结构。

仓库中的 `main.tex` 已放入一组示例信息，可作为填写模板时的参考。实际使用时只需要替换软件名称、文档类型、版本、作者、日期和正文内容即可。

## 项目内容

- `main.tex`：文档编译入口，集中定义软件名称、文档类型、版本、作者和日期等全局信息。
- `config.sty`：LaTeX 样式配置，包含字体、页面、标题、表格、图片、页眉页脚等格式设置。
- `chapter/index.tex`：封面、文档状态、修订记录和目录。
- `chapter/mainbody.tex`：正文模板，包含软件简介、产品概述、开发说明、测试说明和总结规划。
- `figures/`：图片资源目录。
- `refpdf/`：参考资料目录，可放置登记申请相关样例或说明文件。
- `main.pdf`：当前示例编译生成的 PDF 文档。

## 目录结构

```text
.
├── main.tex
├── config.sty
├── clean.bat
├── README.md
├── main.pdf
├── chapter/
│   ├── index.tex
│   └── mainbody.tex
├── figures/
│   └── PeppersRGB.bmp
└── refpdf/
```

## 环境要求

建议使用支持 XeLaTeX 的 LaTeX 发行版：

- Windows：TeX Live 或 MiKTeX
- macOS：MacTeX
- Linux：TeX Live

本模板使用 `SimSun`、`SimHei` 和 `Times New Roman` 字体。若在非 Windows 环境编译，可能需要先安装对应字体，或在 `config.sty` 中替换为本机可用字体。

## 快速开始

1. 编辑 `main.tex` 中的全局信息：

   ```tex
   \newcommand{\SoftwareName}{软件名称}
   \newcommand{\DocType}{设计说明}
   \newcommand{\Version}{V1.0}
   \newcommand{\Authors}{作者姓名}
   \newcommand{\CreatDate}{创建日期}
   ```

2. 在 `chapter/mainbody.tex` 中填写正文内容。

3. 使用 XeLaTeX 编译：

   ```powershell
   xelatex main.tex
   xelatex main.tex
   ```

   连续编译两次可以确保目录、页码和交叉引用正确生成。

4. 编译完成后查看 `main.pdf`。

## 清理编译文件

Windows 环境下可运行：

```powershell
.\clean.bat
```

该脚本会删除 `.aux`、`.log`、`.toc`、`.lof`、`.lot`、`.bak` 等 LaTeX 编译中间文件。

## 编辑说明

- 修改文档基本信息时，优先编辑 `main.tex` 中的全局命令。
- 修改封面、修订记录或目录前置页时，编辑 `chapter/index.tex`。
- 修改正文内容时，编辑 `chapter/mainbody.tex`。
- 添加图片时，将图片放入 `figures/`，并在正文中通过 `\includegraphics` 引用。
- 除非需要调整整体版式，不建议修改 `config.sty`。
- 如果申请材料要求使用“使用说明”，可将 `main.tex` 中的 `\DocType` 从 `设计说明` 修改为 `使用说明`，并同步调整正文小节。

## 文档章节

当前正文包含以下章节框架：

1. 软件简介
2. 产品概述
3. 软件开发说明
4. 软件测试说明
5. 软件总结与未来设计目标

可根据软件著作权登记申请材料要求继续补充各小节内容、插图、表格和引用。

## 注意事项

- 本模板仅提供排版和章节结构参考，最终材料格式应以实际登记申请要求为准。
- 提交前建议检查软件名称、版本号、作者、修订记录、正文截图和页码是否一致。
- 若在非 Windows 环境编译，请确认中文字体配置可用，必要时修改 `config.sty` 中的字体名称。
