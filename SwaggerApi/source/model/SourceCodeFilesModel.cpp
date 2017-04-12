#include "SourceCodeFilesModel.h"

namespace Swagger {
namespace Model {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
SourceCodeFilesModel::SourceCodeFilesModel ( QObject *parent )
    : QObject ( parent ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
SourceCodeFilesModel::SourceCodeFilesModel ( const SourceCodeFilesModel &object )
    : QObject   ( nullptr ) {
    for ( QFileInfo fileInfo : object.sourceCodeFilesReadOnly ( ) ) {
        _sourceCodeFiles.append ( QFileInfo ( fileInfo ) );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
SourceCodeFilesModel::~SourceCodeFilesModel ( ) {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                       Methods & Slots                                          //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SourceCodeFilesModel::fillModelWithRelativeRootPath ( const QString &rootPath ) {
    _clearModel ( );
    QDirIterator dirIterator ( rootPath, _SourceCodeFilesExtension, QDir::Files | QDir::Dirs,
                               QDirIterator::Subdirectories | QDirIterator::FollowSymlinks );
    while ( dirIterator.hasNext ( ) ) {
        _currentSourceCodeFile = dirIterator.fileInfo ( );
        _addCurrentSourceCodeFileToModel ( );
        dirIterator.next ( );
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void SourceCodeFilesModel::_clearModel ( ) {
    _sourceCodeFiles.clear ( );
}
// ───────────────────────────────────────────────────────────────────────────────────────────── //
void SourceCodeFilesModel::_addCurrentSourceCodeFileToModel ( ) {
    if ( _isCurrentSourceCodeFileValid ( ) ) {
        _sourceCodeFiles.append ( _currentSourceCodeFile );
    }
}
// ───────────────────────────────────────────────────────────────────────────────────────────── //
bool SourceCodeFilesModel::_isCurrentSourceCodeFileValid ( ) {
    return ( !_currentSourceCodeFile.fileName ( ).isEmpty ( )
             && ( _currentSourceCodeFile.fileName ( ) != '.' )
             && ( _currentSourceCodeFile.fileName ( ) != ".." ) );
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// - proeprty
QFileInfoList &SourceCodeFilesModel::sourceCodeFiles ( ) {
    return _sourceCodeFiles;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
QFileInfoList SourceCodeFilesModel::sourceCodeFilesReadOnly ( ) const {
    return _sourceCodeFiles;
}

} // Swagger
} // Model
