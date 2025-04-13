#ifndef CONST_H
#define CONST_H

#include <QString>

namespace Const {

enum class NavIndex {
    kMusic = 1,
    kListenBook = 2,
    kLive = 3,
    kMyFavorite = 4,
    kRecentlyPlayer = 5,
    kLocalDownload = 6,
};


const QString kTitleToolBtnName = "titleToolBtn";

const QString kRevokeIconPath = ":/resource/images/return.svg";
const QString kRefreshIconPath = ":/resource/images/refresh.svg";

const QString kMinimizeIconPath = ":/resource/images/minimize.svg";
const QString kNormalizationIconPath = ":/resource/images/normalization.svg";
const QString kMaximizeIconPath = ":/resource/images/maximize.svg";
const QString kCloseIconPath = ":/resource/images/close.svg";

const QString kLogoIconPath = ":/resource/images/logo.svg";
const QString kMusciIconPath = ":/resource/images/music.svg";
const QString kBookIconPath = ":/resource/images/book.svg";
const QString kLiveIconPath = ":/resource/images/camera.svg";
const QString kFavortieIconPath = ":/resource/images/favorite.svg";
const QString kTimeIconPath = ":/resource/images/time.svg";
const QString kDownLoadIconPath = ":/resource/images/download.svg";



const QString kDefaultSongImgPath = ":/resource/images/song..jpg";
const QString kLastIconPath = ":/resource/images/last.svg";
const QString kNextIconPath = ":/resource/images/next.svg";
const QString kStopIconPath = ":/resource/images/stop.svg";
const QString kPlayIconPath = ":/resource/images/play.svg";


const QString kQssPath = ":/resource/qss/styles.qss";


//  navigtion bar

const QString kProjectChName = "XD音乐";
const QString kProjectEnName = "XDMusic";

const QString kNavMusicChName = "音乐";
const QString kNavMusicEnName = "music";

const QString kNavBookChName = "听书";
const QString kNavBookEnName = "listen_book";

const QString kNavLiveChName = "直播";
const QString kNavLiveEnName = "live";


const QString kNavFavoriteChName = "我的收藏";
const QString kNavFavoriteEnName = "my_favorite";

const QString kNavRecentlyPlayedChName = "最近播放";
const QString kNavRecentlyPlayedEnName = "recently_played";

const QString kNavLocalDownloadChName = "本地下载";
const QString kNavLocalDownloadEnName = "local_download";






}

#endif // CONST_H
