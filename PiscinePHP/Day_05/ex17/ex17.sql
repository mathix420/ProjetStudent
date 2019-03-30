SELECT COUNT(`id_member`) AS `nb_susc`,
    FLOOR(AVG(subscription.price)) AS `av_subsc`,
    SUM(subscription.duration_sub % 42) AS `ft`
FROM member
JOIN `subscription` ON subscription.id_sub = member.id_sub;
